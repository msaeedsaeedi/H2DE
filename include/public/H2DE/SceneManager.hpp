#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "H2DE/Scene/Scene.hpp"

namespace H2DE
{
    class SceneManager
    {
        private:
            SceneManager() = delete;
            SceneManager(const SceneManager&) = delete;
            SceneManager& operator=(const SceneManager&) = delete;

        public:
            static void add_scene(const std::string& name,
                                  const std::shared_ptr<Scene>& scene);
            static void change_scene(const std::string& name);
            static void remove_scene(const std::string& name);

            static std::shared_ptr<Scene> get_scene(const std::string& name);
            static std::shared_ptr<Scene> get_current_scene();

        private:
            static std::unordered_map<std::string, std::shared_ptr<Scene>>
                m_scenes;
            static std::shared_ptr<Scene> m_current_scene;
    };
}  // namespace H2DE
