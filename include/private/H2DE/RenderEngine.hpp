#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "H2DE/Object/Object.hpp"

namespace H2DE
{
    /**
     * @class RenderEngine
     * @brief Handles the rendering of all game objects to the window.
     *
     * The RenderEngine class is responsible for clearing the window, rendering
     * all game objects in the current scene, and displaying the final frame. It
     * utilizes SFML for rendering.
     */
    class RenderEngine
    {
        public:
            /**
             * @brief Default constructor.
             */
            RenderEngine() = default;

        public:
            /**
             * @brief Constructs the RenderEngine with a render window.
             *
             * This constructor initializes the RenderEngine with a shared
             * pointer to an SFML render window.
             *
             * @param window A shared pointer to the SFML render window.
             */
            RenderEngine(std::shared_ptr<sf::RenderWindow> window);

        public:
            /**
             * @brief default Destructor.
             */
            ~RenderEngine() = default;

        public:
            /**
             * @brief Renders the current scene.
             *
             * This method clears the window, renders all game objects in the
             * current scene, and then displays the final frame on the window.
             */
            void render() const;

        private:
            /**
             * @brief Shared pointer to the SFML render window.
             */
            std::shared_ptr<sf::RenderWindow> m_window;
    };
};  // namespace H2DE
