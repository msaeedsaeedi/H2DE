#pragma once
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <string>
#include <vector>

#include "H2DE/Exceptions/IOExceptions.hpp"

namespace H2DE
{
    class AssetManager
    {
        private:
            static std::vector<sf::Texture> &get_textures();

        public:
            static const std::tuple<uint32_t, float, float> load_texture(
                const std::string &url);
            static const sf::Texture &get_texture(uint32_t id);

        private:
            AssetManager() = delete;
            AssetManager(const AssetManager &) = delete;
            AssetManager &operator=(const AssetManager &) = delete;
    };
};  // namespace H2DE