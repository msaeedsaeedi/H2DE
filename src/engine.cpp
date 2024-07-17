#include "H2DE/engine.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

#include "H2DE/render_engine.hpp"
#include "H2DE/scene_manager.hpp"
#include "H2DE/utils/readconfig.hpp"

struct H2DE::Engine::Impl {
        bool m_running = false;
        uint16_t m_fps;
        std::shared_ptr<RenderEngine> m_render_engine;
        Objects_t m_objects;
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
        m_impl->m_render_engine->init(height, width, title);
    } catch (const H2DE::H2DEException& e) {
        std::cerr << e.what() << std::endl;
        H2DE::Engine::exit();
    }
}

void H2DE::Engine::run() {
    try {
        const std::chrono::duration<double> frame_duration(1.0 / m_impl->m_fps);
        auto previous_time = std::chrono::high_resolution_clock::now();
        while (m_impl->m_running) {
            auto current_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> delta_time =
                current_time - previous_time;
            if (delta_time.count() < frame_duration.count())
                continue;
            previous_time = current_time;

            auto current_scene = SceneManager::get_current_scene();

            process_events();
            current_scene->update(delta_time.count());
            m_impl->m_render_engine->render(m_impl->m_objects);
        }
    } catch (const H2DE::H2DEException& e) {
        std::cerr << e.what() << std::endl;
        H2DE::Engine::exit();
    }
}

void H2DE::Engine::exit() {
    m_impl->m_running = false;
}

void H2DE::Engine::process_events() {

}

H2DE::Engine::~Engine() = default;
