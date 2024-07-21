#pragma once

#include <functional>
#include <memory>
#include <variant>

#include "H2DE/Events/Events.hpp"
#include "H2DE/Events/Keys.hpp"

namespace H2DE
{
    using window_resize_callback_t = std::function<void(const int, const int)>;
    using window_default_callback_t = std::function<void()>;
    using window_callback_t =
        std::variant<window_default_callback_t, window_resize_callback_t>;

    using keyboard_callback_t = std::function<void(const H2DE::KeyState&)>;

    using mouse_move_callback_t = std::function<void(const int, const int)>;
    using mouse_key_callback_t = std::function<void(const H2DE::KeyState&)>;
    using mouse_scroll_callback_t = std::function<void(const float)>;
    using mouse_callback_t =
        std::variant<mouse_move_callback_t, mouse_key_callback_t,
                     mouse_scroll_callback_t>;

    using text_callback_t = std::function<void(const std::string&)>;

    class EventHandler
    {
        private:
            friend class Engine;
            struct Impl;

        public:
            EventHandler() = delete;
            EventHandler(const EventHandler& other) = delete;
            EventHandler& operator=(const EventHandler& other) = delete;

            static void listen_window_events(const WindowEventType& type,
                                             const window_callback_t& callback);
            static void listen_keyboard(const Key&,
                                        const keyboard_callback_t& callback);
            static void listen_mouse(const MouseEventType&,
                                     const mouse_callback_t& callback);
            static void listen_text(const text_callback_t& callback);

        private:
            static std::unique_ptr<Impl>& getImpl() noexcept;
            static void process_events();
    };
}  // namespace H2DE
