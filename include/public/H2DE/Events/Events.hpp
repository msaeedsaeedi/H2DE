#pragma once

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
};  // namespace H2DE
