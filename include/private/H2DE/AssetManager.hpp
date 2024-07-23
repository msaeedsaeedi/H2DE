#pragma once
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <string>
#include <vector>

#include "H2DE/Exceptions/IOExceptions.hpp"

namespace H2DE
{
    /**
     * @class AssetManager
     * @brief Manages the loading and retrieval of game assets.
     *
     * The AssetManager class is responsible for loading assets from files and
     * providing access to these assets via unique IDs. It maintains a static
     * collection of assets that can be accessed throughout the game.
     */
    class AssetManager
    {
        private:
            /**
             * @brief Deleted default constructor to prevent instantiation.
             */
            AssetManager() = delete;

        private:
            /**
             * @brief Deleted copy constructor to prevent copying.
             */
            AssetManager(const AssetManager &) = delete;

        private:
            /**
             * @brief Deleted assignment operator to prevent assignment.
             *
             * @return AssetManager& Reference to the AssetManager object.
             */
            AssetManager &operator=(const AssetManager &) = delete;

        public:
            /**
             * @brief default Destructor.
             */
            ~AssetManager() = default;

        public:
            /**
             * @brief Loads a texture from a file.
             *
             * This static method loads a texture from the given file URL. If
             * the texture is successfully loaded, it is added to the internal
             * collection and a tuple containing the texture ID, width, and
             * height is returned.
             *
             * @param url The file path of the texture to load.
             * @return A tuple containing the texture ID, width, and height.
             * @throws H2DE::IOException if the texture fails to load.
             */
            static const std::tuple<uint32_t, float, float> load_texture(const std::string &url);

        public:
            /**
             * @brief Retrieves a texture by its ID.
             *
             * This static method returns a reference to the texture associated
             * with the given ID.
             *
             * @param id The unique identifier of the texture.
             * @return A reference to the texture.
             * @throws H2DE::H2DEException if the texture ID is out of range.
             */
            static const sf::Texture &get_texture(uint32_t id);

        private:
            /**
             * @brief Retrieves the collection of loaded textures.
             *
             * This static method returns a reference to the vector containing
             * all loaded textures.
             *
             * @return A reference to the vector of loaded textures.
             */
            static std::vector<sf::Texture> &get_textures();
    };
};  // namespace H2DE
