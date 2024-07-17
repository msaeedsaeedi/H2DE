#pragma once

#include <memory>
#include <vector>

#include "H2DE/object.hpp"
#include <SFML/Graphics.hpp>


namespace H2DE
{
    using Objects_t = std::vector<std::unique_ptr<Object>>;
    class RenderEngine
    {
        public:
            RenderEngine();
            void init(uint16_t height, uint16_t width, const std::string& title);
            void render(const Objects_t& objects) const;

        private:
            std::unique_ptr<sf::RenderWindow> m_window;
    };
};  // namespace H2DE