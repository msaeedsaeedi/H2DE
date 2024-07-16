#include "H2DE/scene_manager.hpp"

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
    return m_scenes.at(name);
}

std::shared_ptr<Scene> H2DE::SceneManager::get_current_scene() {
    return m_current_scene;
}