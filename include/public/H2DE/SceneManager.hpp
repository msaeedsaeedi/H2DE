#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "H2DE/Scene/Scene.hpp"

namespace H2DE
{
    /**
     * @typedef scenes_t
     * @brief Alias for an unordered map of scene names to shared pointers to Scenes.
     */
    using scenes_t = std::unordered_map<std::string, std::shared_ptr<Scene>>;

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

        private:
            /**
             * @brief Deleted copy constructor to prevent copying.
             */
            SceneManager(const SceneManager&) = delete;

        public:
            /**
             * @brief Destructor.
             */
            ~SceneManager() = default;

        private:
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
             * @throws H2DE::SceneException if the scene name already exists.
             */
            static void add_scene(const std::string& name, const std::shared_ptr<Scene>& scene);

        public:
            /**
             * @brief Changes the current scene to the specified scene.
             *
             * This static method changes the current scene to the scene with the specified name.
             *
             * @param name The name of the scene to switch to.
             * @throws H2DE::SceneException if the scene name does not exist.
             */
            static void change_scene(const std::string& name);

        public:
            /**
             * @brief Removes a scene from the manager.
             *
             * This static method removes the scene with the specified name from the manager.
             *
             * @param name The name of the scene to remove.
             * @throws H2DE::SceneException if the scene name does not exist.
             */
            static void remove_scene(const std::string& name);

        public:
            /**
             * @brief Retrieves a scene by its name.
             *
             * This static method returns a shared pointer to the scene with the specified name.
             *
             * @param name The name of the scene to retrieve.
             * @return A shared pointer to the scene.
             * @throws H2DE::SceneException if the scene name does not exist.
             */
            static std::shared_ptr<Scene> get_scene(const std::string& name);

        public:
            /**
             * @brief Retrieves the current active scene.
             *
             * This static method returns a shared pointer to the current active scene.
             *
             * @return A shared pointer to the current scene.
             * @throws H2DE::SceneException if there is no current scene.
             */
            static std::shared_ptr<Scene> get_current_scene();

        private:
            static scenes_t m_scenes; /**< Unordered map of scene names to shared pointers to Scenes */
            static std::shared_ptr<Scene> m_current_scene; /**< Shared pointer to the current active scene */
    };
}  // namespace H2DE
