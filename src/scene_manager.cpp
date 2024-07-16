#include "H2DE/scene_manager.hpp"

#include "H2DE/exceptions/scene_exceptions.hpp"

std::unordered_map<std::string, std::shared_ptr<Scene>>
    H2DE::SceneManager::m_scenes;
std::shared_ptr<Scene> H2DE::SceneManager::m_current_scene;

void H2DE::SceneManager::add_scene(const std::string& name,
                                   const std::shared_ptr<Scene>& scene) {
    m_scenes[name] = scene;
    if (m_current_scene == nullptr) {
        m_current_scene = scene;
    }
}

void H2DE::SceneManager::change_scene(const std::string& name) {
    m_current_scene = m_scenes[name];
}

void H2DE::SceneManager::remove_scene(const std::string& name) {
    m_scenes.erase(name);
}

std::shared_ptr<Scene> H2DE::SceneManager::get_scene(const std::string& name) {
    if (m_scenes.find(name) == m_scenes.end()) {
        throw H2DE::SceneException("Scene not found");
    }
    return m_scenes.at(name);
}

std::shared_ptr<Scene> H2DE::SceneManager::get_current_scene() {
    if (m_current_scene == nullptr) {
        throw H2DE::SceneException("No scene is currently set");
    }
    return m_current_scene;
}