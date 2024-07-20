#include "H2DE/components.hpp"

#include "H2DE/asset_manager.hpp"

H2DE::Component::Sprite::Sprite(const std::string& url) {
    auto [m_asset_id, height, width] = H2DE::AssetManager::load_texture(url);
    this->m_asset_id = m_asset_id;
    this->size = {width, height};
}