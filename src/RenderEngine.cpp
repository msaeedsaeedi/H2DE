#include "H2DE/RenderEngine.hpp"

#include "H2DE/AssetManager.hpp"
#include "H2DE/SceneManager.hpp"

H2DE::RenderEngine::RenderEngine(std::shared_ptr<sf::RenderWindow> window) : m_window(window) {
}

void H2DE::RenderEngine::render() const {
    m_window->clear();
    const auto scene = SceneManager::get_current_scene();
    const auto &objects = scene->m_object_manager->get_all();
    for (const auto &object : objects) {
        const auto &sprite_component = object->get_component<Component::Sprite>();
        const auto &transform_component = object->get_component<Component::Transform>();
        if (sprite_component.has == false || transform_component.has == false)
            continue;

        sf::Sprite sprite;
        const auto &texture = AssetManager::get_texture(sprite_component.m_asset_id);
        sprite.setTexture(texture);
        sprite.setPosition(transform_component.position.first, transform_component.position.second);
        sprite.setScale(transform_component.scale.first, transform_component.scale.second);
        sprite.setRotation(transform_component.rotation);
        sprite.setOrigin(sprite_component.origin.first, sprite_component.origin.second);
        m_window->draw(sprite);
    }
    m_window->display();
}