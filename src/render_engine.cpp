#include "H2DE/render_engine.hpp"

H2DE::RenderEngine::RenderEngine()
    : m_window(std::make_unique<sf::RenderWindow>()) {
}

void H2DE::RenderEngine::init(uint16_t height, uint16_t width,
                              const std::string &title, bool full_screen) {
    this->m_window->create(sf::VideoMode(width, height), title,
                           (full_screen) ? (sf::Style::Fullscreen) : 7U);
}

void H2DE::RenderEngine::render(const Objects_t &objects) const {
    m_window->clear();
    for (const auto &object : objects) {
        // Draw object here
    }
    m_window->display();
}

H2DE::RenderEngine::~RenderEngine() = default;