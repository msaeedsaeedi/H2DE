#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "H2DE/Scene/Scene.hpp"

namespace H2DE
{
    /**
     * @class SceneManager
     * @brief Manages the creation, switching, and removal of game scenes.
     *
     * The SceneManager class is responsible for adding, changing, and removing scenes within the game.
     * It maintains a collection of scenes and allows switching between them.
     */
    class SceneManager
    {
        private:
            /**
             * @brief Deleted default constructor to prevent instantiation.
             */
            SceneManager() = delete;

            /**
             * @brief Deleted copy constructor to prevent copying.
             */
            SceneManager(const SceneManager&) = delete;

            /**
             * @brief Deleted assignment operator to prevent assignment.
             *
             * @return Reference to the SceneManager instance.
             */
            SceneManager& operator=(const SceneManager&) = delete;

        public:
            /**
             * @brief Adds a new scene to the manager.
             *
             * This static method adds a new scene with the specified name to the manager.
             *
             * @param name The name of the scene.
             * @param scene A shared pointer to the scene to be added.
             */
            static void add_scene(const std::string& name, const std::shared_ptr<Scene>& scene);

            /**
             * @brief Changes the current scene to the specified scene.
             *
             * This static method changes the current scene to the scene with the specified name.
             *
             * @param name The name of the scene to switch to.
             */
            static void change_scene(const std::string& name);

            /**
             * @brief Removes a scene from the manager.
             *
             * This static method removes the scene with the specified name from the manager.
             *
             * @param name The name of the scene to remove.
             */
            static void remove_scene(const std::string& name);

            /**
             * @brief Retrieves a scene by its name.
             *
             * This static method returns a shared pointer to the scene with the specified name.
             *
             * @param name The name of the scene to retrieve.
             * @return A shared pointer to the scene.
             */
            static std::shared_ptr<Scene> get_scene(const std::string& name);

            /**
             * @brief Retrieves the current active scene.
             *
             * This static method returns a shared pointer to the current active scene.
             *
             * @return A shared pointer to the current scene.
             */
            static std::shared_ptr<Scene> get_current_scene();

        private:
            /**
             * @brief Collection of scenes managed by the SceneManager.
             */
            static std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;

            /**
             * @brief The current active scene.
             */
            static std::shared_ptr<Scene> m_current_scene;
    };
}  // namespace H2DE
