#pragma once
#include <string>
#include <utility>

namespace H2DE
{
    class RenderEngine;

    namespace Component
    {
        /**
         * @class Transform
         * @brief Component for handling position, scale, and rotation of game objects.
         *
         * The Transform component manages the spatial properties of game objects, such as their
         * position, scale, and rotation.
         */
        class Transform
        {
            public:
                /**
                 * @brief Default constructor.
                 */
                Transform() = default;

                /**
                 * @brief Constructs a Transform with specified position.
                 *
                 * This constructor initializes the Transform with the given x and y coordinates.
                 *
                 * @param x The x-coordinate of the position.
                 * @param y The y-coordinate of the position.
                 */
                Transform(float x, float y) : position(x, y) {
                }

                std::pair<float, float> position;          /**< Position of the game object (x, y) */
                std::pair<float, float> scale{1.0f, 1.0f}; /**< Scale of the game object (x, y) */
                float rotation = 0.0f;                     /**< Rotation of the game object in degrees */

                bool has = false; /**< Indicates if the component is valid/active */
        };

        /**
         * @class Sprite
         * @brief Component for handling the rendering of game object sprites.
         *
         * The Sprite component manages the visual representation of game objects using textures.
         */
        class Sprite
        {
            private:
                friend class H2DE::RenderEngine;

            public:
                /**
                 * @brief Default constructor.
                 */
                Sprite() = default;

                /**
                 * @brief Constructs a Sprite with a specified texture URL.
                 *
                 * This constructor initializes the Sprite with a texture loaded from the given URL.
                 *
                 * @param url The file path of the texture to load.
                 */
                Sprite(const std::string& url);

                std::pair<float, float> origin; /**< Origin of the sprite (x, y) */
                std::pair<float, float> size;   /**< Size of the sprite (width, height) */

                bool has = false; /**< Indicates if the component is valid/active */

            private:
                uint32_t m_asset_id; /**< Asset ID of the texture */
        };
    }  // namespace Component
}  // namespace H2DE
