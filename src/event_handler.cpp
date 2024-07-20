#include "H2DE/Events/event_handler.hpp"

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

struct H2DE::EventHandler::Impl {
        std::shared_ptr<sf::RenderWindow> m_window;

        std::unordered_map<WindowEventType, std::vector<window_callback_t>>
            window_callbacks;
        std::unordered_map<Key, std::vector<key_callback_t>> key_callbacks;
        std::vector<mouse_callback_t> mouse_callbacks;
        std::vector<text_callback_t> text_callbacks;

        void process_window_events(const sf::Event& event);
        void process_key_events();
        void process_mouse_events(const sf::Event& event);
        void process_text_events(const sf::Event& event);
};

std::unique_ptr<H2DE::EventHandler::Impl>&
H2DE::EventHandler::getImpl() noexcept {
    static std::unique_ptr<Impl> m_impl =
        std::make_unique<EventHandler::Impl>();
    return m_impl;
}

void H2DE::EventHandler::process_events() {
    auto& impl = getImpl();
    sf::Event event;
    while (impl->m_window->pollEvent(event)) {
        impl->process_window_events(event);
        impl->process_mouse_events(event);
        impl->process_text_events(event);
    }
    impl->process_key_events();
}

void H2DE::EventHandler::Impl::process_window_events(const sf::Event& event) {
    const auto& callbacks =
        window_callbacks[static_cast<WindowEventType>(event.type)];
    for (const auto& callback : callbacks) {
        callback();
    }
}

void H2DE::EventHandler::Impl::process_key_events() {
    for (const auto& [key, callbacks] : key_callbacks) {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key))) {
            for (const auto& callback : callbacks) {
                callback(KeyActionType::Pressed);
            }
        } else {
            for (const auto& callback : callbacks) {
                callback(KeyActionType::Released);
            }
        }
    }
}

void H2DE::EventHandler::Impl::process_mouse_events(const sf::Event& event) {
}

void H2DE::EventHandler::Impl::process_text_events(const sf::Event& event) {
}

void H2DE::EventHandler::listen_window_events(
    const WindowEventType& type, const window_callback_t& callback) {
    getImpl()->window_callbacks[type].push_back(callback);
}

void H2DE::EventHandler::listen_key(const Key& key,
                                    const key_callback_t& callback) {
    getImpl()->key_callbacks[key].push_back(callback);
}

void H2DE::EventHandler::listen_mouse(const mouse_callback_t& callback) {
    getImpl()->mouse_callbacks.push_back(callback);
}

void H2DE::EventHandler::listen_text(const text_callback_t& callback) {
    getImpl()->text_callbacks.push_back(callback);
}

H2DE::EventHandler::~EventHandler() {
}