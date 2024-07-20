#include "H2DE/asset_manager.hpp"

std::vector<sf::Texture> &H2DE::AssetManager::get_textures() {
    static std::vector<sf::Texture> m_textures;
    return m_textures;
}

uint32_t H2DE::AssetManager::load_texture(const std::string &url) {
    sf::Texture texture;
    if (!texture.loadFromFile(url)) {
        throw H2DE::IOException(url);
    }
    get_textures().push_back(texture);
    return get_textures().size() - 1;
}

const sf::Texture &H2DE::AssetManager::get_texture(uint32_t id) {
    if (id >= get_textures().size())
        throw H2DE::H2DEException("Asset Manager", "Texture ID out of range");
    return get_textures().at(id);
}