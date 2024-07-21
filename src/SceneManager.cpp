#include "H2DE/Exceptions/SceneException.hpp"
#include "H2DE/SceneManager.hpp"

std::unordered_map<std::string, std::shared_ptr<H2DE::Scene>>
    H2DE::SceneManager::m_scenes;
std::shared_ptr<H2DE::Scene> H2DE::SceneManager::m_current_scene;

void H2DE::SceneManager::add_scene(const std::string& name,
                                   const std::shared_ptr<H2DE::Scene>& scene) {
    if (m_scenes.find(name) != m_scenes.end())
        throw H2DE::SceneException("Scene `" + name + "` already exists");
    m_scenes[name] = scene;
    if (m_current_scene == nullptr) {
        m_current_scene = scene;
        m_current_scene->init();
    }
}

void H2DE::SceneManager::change_scene(const std::string& name) {
    if (m_scenes.find(name) == m_scenes.end()) {
        throw H2DE::SceneException("Scene '" + name + "' not found");
    }
    m_current_scene = m_scenes[name];
    m_current_scene->init();
}

void H2DE::SceneManager::remove_scene(const std::string& name) {
    if (m_scenes.find(name) == m_scenes.end())
        throw H2DE::SceneException("Scene '" + name + "' not found");
    m_scenes.erase(name);
}

std::shared_ptr<H2DE::Scene> H2DE::SceneManager::get_scene(
    const std::string& name) {
    if (m_scenes.find(name) == m_scenes.end())
        throw H2DE::SceneException("Scene '" + name + "' not found");
    return m_scenes.at(name);
}

std::shared_ptr<H2DE::Scene> H2DE::SceneManager::get_current_scene() {
    if (m_current_scene == nullptr)
        throw H2DE::SceneException("No scene is currently set");
    return m_current_scene;
}