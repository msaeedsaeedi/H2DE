#pragma once

#include <functional>
#include <memory>
#include <variant>

#include "H2DE/Events/Events.hpp"
#include "H2DE/Events/Keys.hpp"

namespace H2DE
{
    /**
     * @typedef window_resize_callback_t
     * @brief Alias for a callback function that handles window resize events.
     */
    using window_resize_callback_t = std::function<void(const int, const int)>;

    /**
     * @typedef window_default_callback_t
     * @brief Alias for a callback function that handles default window events.
     */
    using window_default_callback_t = std::function<void()>;

    /**
     * @typedef window_callback_t
     * @brief Alias for a variant of window event callback functions.
     */
    using window_callback_t = std::variant<window_default_callback_t, window_resize_callback_t>;

    /**
     * @typedef keyboard_callback_t
     * @brief Alias for a callback function that handles keyboard events.
     */
    using keyboard_callback_t = std::function<void(const H2DE::KeyState&)>;

    /**
     * @typedef mouse_move_callback_t
     * @brief Alias for a callback function that handles mouse move events.
     */
    using mouse_move_callback_t = std::function<void(const int, const int)>;

    /**
     * @typedef mouse_key_callback_t
     * @brief Alias for a callback function that handles mouse key events.
     */
    using mouse_key_callback_t = std::function<void(const H2DE::KeyState&)>;

    /**
     * @typedef mouse_scroll_callback_t
     * @brief Alias for a callback function that handles mouse scroll events.
     */
    using mouse_scroll_callback_t = std::function<void(const float)>;

    /**
     * @typedef mouse_callback_t
     * @brief Alias for a variant of mouse event callback functions.
     */
    using mouse_callback_t = std::variant<mouse_move_callback_t, mouse_key_callback_t, mouse_scroll_callback_t>;

    /**
     * @typedef text_callback_t
     * @brief Alias for a callback function that handles text input events.
     */
    using text_callback_t = std::function<void(const std::string&)>;

    /**
     * @class EventHandler
     * @brief Manages event handling for the game engine.
     *
     * The EventHandler class provides methods to listen for various events, including
     * window events, keyboard events, mouse events, and text input events. It uses
     * callback functions to handle these events.
     */
    class EventHandler
    {
        private:
            friend class Engine;
            struct Impl;

        public:
            /**
             * @brief Deleted default constructor to prevent instantiation.
             */
            EventHandler() = delete;

            /**
             * @brief Deleted copy constructor to prevent copying.
             */
            EventHandler(const EventHandler& other) = delete;

            /**
             * @brief Deleted assignment operator to prevent assignment.
             *
             * @return Reference to the EventHandler instance.
             */
            EventHandler& operator=(const EventHandler& other) = delete;

            /**
             * @brief Registers a callback for a specific window event type.
             *
             * This static method registers a callback function to handle a specific type of window event.
             *
             * @param type The type of the window event.
             * @param callback The callback function to handle the event.
             */
            static void listen_window_events(const WindowEventType& type, const window_callback_t& callback);

            /**
             * @brief Registers a callback for a specific keyboard event.
             *
             * This static method registers a callback function to handle a specific keyboard event.
             *
             * @param key The key for which the event should be handled.
             * @param callback The callback function to handle the event.
             */
            static void listen_keyboard(const Key& key, const keyboard_callback_t& callback);

            /**
             * @brief Registers a callback for a specific mouse event type.
             *
             * This static method registers a callback function to handle a specific type of mouse event.
             *
             * @param type The type of the mouse event.
             * @param callback The callback function to handle the event.
             */
            static void listen_mouse(const MouseEventType& type, const mouse_callback_t& callback);

            /**
             * @brief Registers a callback for text input events.
             *
             * This static method registers a callback function to handle text input events.
             *
             * @param callback The callback function to handle the event.
             */
            static void listen_text(const text_callback_t& callback);

        private:
            /**
             * @brief Retrieves the unique instance of the Impl structure.
             *
             * @return A reference to the unique pointer of the Impl structure.
             */
            static std::unique_ptr<Impl>& getImpl() noexcept;

            /**
             * @brief Processes the events.
             *
             * This static method processes all the registered events.
             */
            static void process_events();
    };
}  // namespace H2DE
