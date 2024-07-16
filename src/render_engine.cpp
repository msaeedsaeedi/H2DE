#include "H2DE/render_engine.hpp"

void RenderEngine::set_window(const std::shared_ptr<sf::RenderWindow>& window) {
    this->m_window = window;
}

void RenderEngine::draw() const {
    // Draw stuff
    this->m_window->draw(sf::CircleShape(100));
}