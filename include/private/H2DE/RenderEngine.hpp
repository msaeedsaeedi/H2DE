#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "H2DE/Object/Object.hpp"

namespace H2DE
{
    class RenderEngine
    {
        public:
            RenderEngine() = default;
            RenderEngine(std::shared_ptr<sf::RenderWindow> window);
            ~RenderEngine();
            void render() const;

        private:
            std::shared_ptr<sf::RenderWindow> m_window;
    };
};  // namespace H2DE