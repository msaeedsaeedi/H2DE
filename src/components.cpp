#include "H2DE/components.hpp"

#include "H2DE/asset_manager.hpp"

H2DE::Component::Sprite::Sprite(const std::string& url) {
    asset_id = H2DE::AssetManager::load_texture(url);
}