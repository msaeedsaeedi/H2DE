#pragma once

#include <memory>

#include "H2DE/ObjectManager.hpp"

namespace H2DE
{
    /**
     * @class Scene
     * @brief Represents a game scene containing objects and managing their lifecycle.
     *
     * The Scene class is an abstract base class for all game scenes. It manages the objects
     * within the scene, provides methods for initialization and updates, and keeps track
     * of the time delta between frames.
     */
    class Scene
    {
        public:
            friend class RenderEngine;
            friend class Engine;

        public:
            /**
             * @brief Default constructor.
             */
            Scene();

        public:
            /**
             * @brief Virtual destructor.
             */
            virtual ~Scene() = default;

        public:
            /**
             * @brief Initializes the scene.
             *
             * This pure virtual method must be implemented by derived classes to initialize
             * the scene, including loading resources, setting up objects, and declaring input callbacks.
             */
            virtual void init() = 0;

        public:
            /**
             * @brief Updates the scene.
             *
             * This pure virtual method must be implemented by derived classes to update the
             * scene logic and updating object states.
             */
            virtual void update() = 0;

        public:
            /**
             * @brief Retrieves the time delta between frames.
             *
             * @return The time delta between frames in seconds.
             */
            const float get_delta() const noexcept;

        protected:
            std::unique_ptr<ObjectManager> m_object_manager; /**< Unique pointer to the object manager */

        private:
            float m_delta = 0.0f; /**< Time delta between frames */
    };
}  // namespace H2DE
