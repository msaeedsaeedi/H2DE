#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class RenderEngine
{
    public:
        void set_window(const std::shared_ptr<sf::RenderWindow>& window);
        void draw() const;

    private:
        std::shared_ptr<sf::RenderWindow> m_window;
};