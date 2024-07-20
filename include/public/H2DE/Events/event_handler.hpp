#pragma once

#include <functional>
#include <memory>

#include "H2DE/Events/events.hpp"
#include "H2DE/Events/key.hpp"

namespace H2DE
{
    using window_callback_t = std::function<void()>;
    using key_callback_t = std::function<void(const KeyActionType&)>;
    using mouse_callback_t = std::function<void()>;
    using text_callback_t = std::function<void()>;

    class EventHandler
    {
        private:
            friend class Engine;
            struct Impl;

        public:
            EventHandler() = delete;
            EventHandler(const EventHandler& other) = delete;
            EventHandler& operator=(const EventHandler& other) = delete;

            ~EventHandler();
            static void listen_window_events(const WindowEventType& type,
                                             const window_callback_t& callback);
            static void listen_key(const Key&, const key_callback_t& callback);
            static void listen_mouse(const mouse_callback_t& callback);
            static void listen_text(const text_callback_t& callback);

        private:
            static std::unique_ptr<Impl>& getImpl() noexcept;
            static void process_events();
    };
}  // namespace H2DE
