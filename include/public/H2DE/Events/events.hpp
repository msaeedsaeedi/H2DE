#pragma once

namespace H2DE
{
    enum class WindowEventType {
        WINDOW_CLOSE,
        WINDOW_RESIZE,
        WINDOW_LOST_FOCUS,
        WINDOW_GAINED_FOCUS,
        TEXT_ENTERED
    };

    enum class KeyActionType {
        Pressed,
        Released,
    };

    enum class MouseEventType {
        MOUSE_MOVED,
        MOUSE_KEYPRESSED,
        MOUSE_KEYRELEASED,
        MOUSE_ENTERED,
        MOUSE_LEFT,
        MOUSE_WHEEL_MOVED
    };
};