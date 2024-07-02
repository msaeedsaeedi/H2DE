#include "H2DE/engine.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "H2DE/utils/readconfig.hpp"

struct H2DE::Engine::Impl {
        sf::RenderWindow m_window;
};

H2DE::Engine::Engine() {
    m_impl = std::make_unique<Impl>();
}

void H2DE::Engine::init(const std::string& config_file) {
    utils::read_config config(config_file);

    int width = config.get<int>("window.width");
    int height = config.get<int>("window.height");
    std::string title = config.get<std::string>("window.title");

    m_impl->m_window.create(sf::VideoMode(width, height), title);
}

void H2DE::Engine::run() {
    while (m_impl->m_window.isOpen()) {
        sf::Event event;
        while (m_impl->m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_impl->m_window.close();
            }
        }
        m_impl->m_window.clear();
        m_impl->m_window.display();
    }
}

H2DE::Engine::~Engine() = default;
