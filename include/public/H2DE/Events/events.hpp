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
        MOUSE_WHEEL_SCROLLED = 8,
        MOUSE_KEY = 9,
        MOUSE_MOVED = 11,
    };
};  // namespace H2DE