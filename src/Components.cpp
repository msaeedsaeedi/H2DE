#include "H2DE/Object/Components.hpp"

#include "H2DE/AssetManager.hpp"

H2DE::Component::Sprite::Sprite(const std::string& url) {
    auto [m_asset_id, height, width] = H2DE::AssetManager::load_texture(url);
    this->m_asset_id = m_asset_id;
    this->size = {width, height};
}