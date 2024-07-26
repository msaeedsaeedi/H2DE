#pragma once

#include <functional>
#include <string>
#include <variant>

namespace H2DE
{
    /**
     * @enum WindowEventType
     * @brief Enum class for window event types.
     *
     * This enum class defines various types of window events, such as closing,
     * resizing, gaining or losing focus, and mouse events like entering or
     * leaving the window.
     */
    enum class WindowEventType {
        WINDOW_CLOSE,        /**< Event type for window close */
        WINDOW_RESIZE,       /**< Event type for window resize */
        WINDOW_LOST_FOCUS,   /**< Event type for window losing focus */
        WINDOW_GAINED_FOCUS, /**< Event type for window gaining focus */
        MOUSE_ENTERED = 12,  /**< Event type for mouse entering the window */
        MOUSE_LEFT = 13,     /**< Event type for mouse leaving the window */
    };

    /**
     * @enum KeyState
     * @brief Enum class for key states.
     *
     * This enum class defines the states of a key, such as pressed or released.
     */
    enum class KeyState {
        PRESSED,  /**< Key state for when a key is pressed */
        RELEASED, /**< Key state for when a key is released */
    };

    /**
     * @enum MouseEventType
     * @brief Enum class for mouse event types.
     *
     * This enum class defines various types of mouse events, such as scrolling,
     * mouse button actions, and mouse movement.
     */
    enum class MouseEventType {
        MOUSE_WHEEL_SCROLLED = 8, /**< Event type for mouse wheel scrolled */
        MOUSE_KEY = 9,            /**< Event type for mouse button actions */
        MOUSE_MOVED = 11,         /**< Event type for mouse movement */
    };

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
    using keyboard_callback_t = std::function<void(const H2DE::KeyState &)>;

    /**
     * @typedef mouse_move_callback_t
     * @brief Alias for a callback function that handles mouse move events.
     */
    using mouse_move_callback_t = std::function<void(const int, const int)>;

    /**
     * @typedef mouse_key_callback_t
     * @brief Alias for a callback function that handles mouse key events.
     */
    using mouse_key_callback_t = std::function<void(const H2DE::KeyState &)>;

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
    using text_callback_t = std::function<void(const std::string &)>;
};  // namespace H2DE
