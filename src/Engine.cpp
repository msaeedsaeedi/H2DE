#include "H2DE/Engine.hpp"

#include <chrono>

#include "H2DE/EventHandler.hpp"
#include "H2DE/RenderEngine.hpp"
#include "H2DE/SceneManager.hpp"
#include "H2DE/utils/Config.hpp"

using namespace H2DE;

struct Engine::Impl {
        bool m_running = false;
        uint16_t m_fps;
        std::shared_ptr<sf::RenderWindow> m_window;
        std::unique_ptr<RenderEngine> m_render_engine;
};

struct H2DE::EventHandler::Impl {
        std::shared_ptr<sf::RenderWindow> m_window;
};

std::unique_ptr<H2DE::Engine::Impl>& H2DE::Engine::getImpl() noexcept {
    static std::unique_ptr<Impl> m_impl = std::make_unique<Engine::Impl>();
    return m_impl;
}

void Engine::init(const std::string& config_file) {
    H2DE::Config config(config_file);

    uint16_t width = config.get<int32_t>("window.width");
    uint16_t height = config.get<int32_t>("window.height");
    uint16_t fps = config.get<int32_t>("window.fps");
    bool full_screen = config.get<bool>("window.fullscreen");
    std::string title = config.get<std::string>("window.title");

    getImpl()->m_window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(width, height), title,
        (full_screen) ? (sf::Style::Fullscreen) : 7U);
    H2DE::EventHandler::getImpl()->m_window = getImpl()->m_window;
    getImpl()->m_render_engine =
        std::make_unique<RenderEngine>(getImpl()->m_window);
    getImpl()->m_fps = fps;
    getImpl()->m_running = true;

    H2DE::EventHandler::listen_window_events(
        H2DE::WindowEventType::WINDOW_CLOSE,
        []() -> void { H2DE::Engine::exit(); });
}

void Engine::run() {
    const std::chrono::duration<double> frame_duration(1.0 / getImpl()->m_fps);
    auto previous_time = std::chrono::high_resolution_clock::now();
    while (getImpl()->m_running) {
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta_time = current_time - previous_time;
        if (delta_time.count() < frame_duration.count())
            continue;
        previous_time = current_time;

        auto current_scene = SceneManager::get_current_scene();

        H2DE::EventHandler::process_events();
        current_scene->m_delta = delta_time.count();
        current_scene->update();
        getImpl()->m_render_engine->render();
    }
}
void Engine::exit() {
    getImpl()->m_running = false;
}

Engine::~Engine() = default;