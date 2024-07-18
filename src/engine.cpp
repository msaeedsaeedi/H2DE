#include "H2DE/engine.hpp"

#include <chrono>

#include "H2DE/render_engine.hpp"
#include "H2DE/scene_manager.hpp"
#include "H2DE/utils/readconfig.hpp"

using namespace H2DE;

struct Engine::Impl {
        bool m_running = false;
        uint16_t m_fps;
        std::unique_ptr<RenderEngine> m_render_engine;
};

std::unique_ptr<H2DE::Engine::Impl>& H2DE::Engine::getImpl() noexcept {
    static std::unique_ptr<Impl> m_impl = std::make_unique<Engine::Impl>();
    return m_impl;
}

void Engine::init(const std::string& config_file) {
    getImpl()->m_render_engine = std::make_unique<RenderEngine>();
    utils::read_config config(config_file);

    uint16_t width = config.get<int32_t>("window.width");
    uint16_t height = config.get<int32_t>("window.height");
    uint16_t fps = config.get<int32_t>("window.fps");
    bool full_screen = config.get<bool>("window.fullscreen");
    std::string title = config.get<std::string>("window.title");

    getImpl()->m_fps = fps;
    getImpl()->m_render_engine->init(height, width, title, full_screen);
    getImpl()->m_running = true;
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

        process_events();
        current_scene->update(delta_time.count());
        getImpl()->m_render_engine->render();
    }
}
void Engine::exit() {
    getImpl()->m_running = false;
}

void Engine::process_events() {
}

Engine::~Engine() = default;