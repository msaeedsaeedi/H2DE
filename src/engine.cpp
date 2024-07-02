#include "H2DE/engine.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "H2DE/game.hpp"
#include "H2DE/utils/readconfig.hpp"

struct H2DE::Engine::Impl {
        sf::RenderWindow m_window;
        std::shared_ptr<Game> m_game;
};

H2DE::Engine::Engine() {
    m_impl = std::make_unique<Impl>();
}

void H2DE::Engine::init(const std::string& config_file) {
    try {
        utils::read_config config(config_file);

        int width = config.get<int>("window.width");
        int height = config.get<int>("window.height");
        std::string title = config.get<std::string>("window.title");

        m_impl->m_window.create(sf::VideoMode(width, height), title);
    } catch (const std::exception& e) {
        std::cerr << "H2DE: " << e.what() << std::endl;
    }
}

void H2DE::Engine::set_game(const std::shared_ptr<Game>& game) {
    try {
        m_impl->m_game = std::move(game);
    } catch (const std::exception& e) {
        std::cerr << "H2DE: " << e.what() << std::endl;
    }
}

void H2DE::Engine::run() {
    try {
        validate_requirements();

        while (m_impl->m_window.isOpen()) {
            sf::Event event;
            while (m_impl->m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    m_impl->m_window.close();
                }
            }

            m_impl->m_game->update();
            m_impl->m_window.clear();
            m_impl->m_window.display();
        }
    } catch (const std::exception& e) {
        std::cerr << "H2DE: " << e.what() << std::endl;
    }
}

void H2DE::Engine::validate_requirements() {
    if (not m_impl->m_game) {
        throw std::logic_error("No Game Instance Found!");
    }
}

H2DE::Engine::~Engine() = default;
