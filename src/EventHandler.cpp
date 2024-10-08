#include "H2DE/EventHandler.hpp"

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

struct H2DE::EventHandler::Impl {
        std::shared_ptr<sf::RenderWindow> m_window;

        std::unordered_map<WindowEventType, std::vector<window_callback_t>> window_callbacks;
        std::unordered_map<Key, std::vector<keyboard_callback_t>> keyboard_callbacks;
        std::unordered_map<Key, std::vector<keyboard_callback_t>> keyboard_live_callbacks;
        std::unordered_map<MouseEventType, std::vector<mouse_callback_t>> mouse_callbacks;
        std::vector<std::pair<std::string, text_callback_t>> text_callbacks;

        void process_window_events(const sf::Event& event);
        void process_key_events(const sf::Event& event);
        void process_live_key_events();
        void process_mouse_events(const sf::Event& event);
        void process_text_events(const sf::Event& event);
};

std::unique_ptr<H2DE::EventHandler::Impl>& H2DE::EventHandler::getImpl() noexcept {
    static std::unique_ptr<Impl> m_impl = std::make_unique<EventHandler::Impl>();
    return m_impl;
}

void H2DE::EventHandler::process_events() {
    auto& impl = getImpl();
    sf::Event event;
    while (impl->m_window->pollEvent(event)) {
        impl->process_window_events(event);
        impl->process_key_events(event);
        impl->process_mouse_events(event);
        impl->process_text_events(event);
    }
    impl->process_live_key_events();
}

void H2DE::EventHandler::Impl::process_window_events(const sf::Event& event) {
    const auto& callbacks = window_callbacks[static_cast<WindowEventType>(event.type)];
    for (const auto& callback : callbacks) {
        switch (event.type) {
            case sf::Event::Resized:
                std::get<1>(callback)(event.size.width, event.size.height);
                break;
            default:
                std::get<0>(callback)();
                break;
        }
    }
}

void H2DE::EventHandler::Impl::process_live_key_events() {
    for (const auto& [key, callbacks] : keyboard_live_callbacks) {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key))) {
            for (const auto& callback : callbacks) {
                callback(KeyState::PRESSED);
            }
        } else {
            for (const auto& callback : callbacks) {
                callback(KeyState::RELEASED);
            }
        }
    }
}
void H2DE::EventHandler::Impl::process_key_events(const sf::Event& event) {
    auto key = static_cast<Key>(event.key.code);
    const auto& callbacks = keyboard_callbacks[key];
    for (const auto& callback : callbacks) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                callback(KeyState::PRESSED);
                break;
            case sf::Event::KeyReleased:
                callback(KeyState::RELEASED);
                break;
        }
    }
}

void H2DE::EventHandler::Impl::process_mouse_events(const sf::Event& event) {
    auto key = static_cast<MouseEventType>(event.type);
    const auto& callbacks = mouse_callbacks[static_cast<int>(key) == 10 ? MouseEventType::MOUSE_KEY : key];
    for (const auto& callback : callbacks) {
        switch (event.type) {
            case sf::Event::MouseMoved:
                std::get<0>(callback)(event.mouseMove.x, event.mouseMove.y);
                break;
            case sf::Event::MouseButtonPressed:
                std::get<1>(callback)(KeyState::PRESSED);
                break;
            case sf::Event::MouseButtonReleased:
                std::get<1>(callback)(KeyState::RELEASED);
                break;
            case sf::Event::MouseWheelScrolled:
                std::get<2>(callback)(event.mouseWheelScroll.delta);
                break;
        }
    }
}

void H2DE::EventHandler::Impl::process_text_events(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        for (auto& [text, callback] : text_callbacks) {
            if (event.text.unicode == '\b') {
                if (!text.empty())
                    text.pop_back();
            }
            if (event.text.unicode >= 32 && event.text.unicode <= 127)
                text += static_cast<char>(event.text.unicode);
            callback(text);
        }
    }
}

void H2DE::EventHandler::listen_window_events(const WindowEventType& type, const window_callback_t& callback) noexcept {
    getImpl()->window_callbacks[type].push_back(callback);
}

void H2DE::EventHandler::listen_keyboard(const Key& key, const keyboard_callback_t& callback, bool live) noexcept {
    if (live)
        getImpl()->keyboard_live_callbacks[key].push_back(callback);
    else
        getImpl()->keyboard_callbacks[key].push_back(callback);
}

void H2DE::EventHandler::listen_mouse(const MouseEventType& type, const mouse_callback_t& callback) noexcept {
    getImpl()->mouse_callbacks[type].push_back(callback);
}

void H2DE::EventHandler::listen_text(const text_callback_t& callback) noexcept {
    getImpl()->text_callbacks.push_back({"", callback});
}