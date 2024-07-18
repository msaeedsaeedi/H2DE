#include "H2DE/render_engine.hpp"

#include "H2DE/scene_manager.hpp"

H2DE::RenderEngine::RenderEngine()
    : m_window(std::make_unique<sf::RenderWindow>()) {
}

void H2DE::RenderEngine::init(uint16_t height, uint16_t width,
                              const std::string &title, bool full_screen) {
    this->m_window->create(sf::VideoMode(width, height), title,
                           (full_screen) ? (sf::Style::Fullscreen) : 7U);
}

void H2DE::RenderEngine::render() const {
    m_window->clear();
    const auto scene = SceneManager::get_current_scene();
    const auto &objects = scene->m_object_manager->get_all();
    for (const auto &object : objects) {
        sf::CircleShape shape(100.0f);
        shape.setFillColor(sf::Color::Green);
        float x = object->get_component<Component::Transform>().position.first;
        float y = object->get_component<Component::Transform>().position.second;
        shape.setPosition(x, y);
        m_window->draw(shape);
    }
    m_window->display();
}

H2DE::RenderEngine::~RenderEngine() = default;