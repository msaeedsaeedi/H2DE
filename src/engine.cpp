#include "H2DE/engine.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

#include "H2DE/scene_manager.hpp"
#include "H2DE/utils/readconfig.hpp"

struct H2DE::Engine::Impl {
        sf::RenderWindow m_window;
        uint16_t m_fps;
};

std::unique_ptr<H2DE::Engine::Impl> H2DE::Engine::m_impl =
    std::make_unique<H2DE::Engine::Impl>();

H2DE::Engine::Engine() {
}

void H2DE::Engine::init(const std::string& config_file) {
    try {
        utils::read_config config(config_file);

        uint16_t width = config.get<int32_t>("window.width");
        uint16_t height = config.get<int32_t>("window.height");
        uint16_t fps = config.get<int32_t>("window.fps");
        std::string title = config.get<std::string>("window.title");
        m_impl->m_fps = fps;

        m_impl->m_window.create(sf::VideoMode(width, height), title);
    } catch (const H2DE::H2DEException& e) {
        std::cerr << e.what() << std::endl;
        H2DE::Engine::exit();
    }
}

void H2DE::Engine::run() {
    try {
        const std::chrono::duration<double> frame_duration(1.0 / m_impl->m_fps);
        auto previous_time = std::chrono::high_resolution_clock::now();
        while (m_impl->m_window.isOpen()) {
            auto current_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> delta_time =
                current_time - previous_time;
            if (delta_time.count() < frame_duration.count())
                continue;
            previous_time = current_time;

            auto current_scene = SceneManager::get_current_scene();

            process_events();
            current_scene->update(delta_time.count());
            m_impl->m_window.clear();
            current_scene->render();
            m_impl->m_window.display();
        }
    } catch (const H2DE::H2DEException& e) {
        std::cerr << e.what() << std::endl;
        H2DE::Engine::exit();
    }
}

void H2DE::Engine::exit() {
    m_impl->m_window.close();
}

void H2DE::Engine::process_events() {
    sf::Event event;
    while (m_impl->m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_impl->m_window.close();
        }
    }
}
H2DE::Engine::~Engine() = default;
