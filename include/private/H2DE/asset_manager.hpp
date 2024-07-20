#pragma once
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <string>
#include <vector>

#include "H2DE/exceptions/io_exceptions.hpp"

namespace H2DE
{
    class AssetManager
    {
        private:
            static std::vector<sf::Texture> &get_textures();

        public:
            static uint32_t load_texture(const std::string &url);
            static const sf::Texture &get_texture(uint32_t id);

        private:
            AssetManager() = delete;
            AssetManager(const AssetManager &) = delete;
            AssetManager &operator=(const AssetManager &) = delete;
    };
};  // namespace H2DE