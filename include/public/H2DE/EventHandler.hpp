#pragma once

#include <memory>

#include "H2DE/Events/Events.hpp"
#include "H2DE/Events/Keys.hpp"

namespace H2DE
{

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
        public:
            friend class Engine;

        private:
            /**
             * @struct Impl
             * @brief Internal implementation structure for the EventHandler class.
             */
            struct Impl;

        public:
            /**
             * @brief Deleted default constructor to prevent instantiation.
             */
            EventHandler() = delete;

        public:
            /**
             * @brief Deleted copy constructor to prevent copying.
             */
            EventHandler(const EventHandler& other) = delete;

        public:
            /**
             * @brief default Destructor.
             */
            ~EventHandler() = default;

        public:
            /**
             * @brief Deleted assignment operator to prevent assignment.
             *
             * @return Reference to the EventHandler instance.
             */
            EventHandler& operator=(const EventHandler& other) = delete;

        public:
            /**
             * @brief Registers a callback for a specific window event type.
             *
             * This static method registers a callback function to handle a specific type of window event.
             *
             * @param type The type of the window event.
             * @param callback The callback function to handle the event.
             */
            static void listen_window_events(const WindowEventType& type, const window_callback_t& callback) noexcept;

        public:
            /**
             * @brief Registers a callback for a specific keyboard event.
             *
             * This static method registers a callback function to handle a specific keyboard event.
             *
             * @param key The key for which the event should be handled.
             * @param callback The callback function to handle the event.
             * @param live A flag indicating whether the event should be handled in real-time.
             */
            static void listen_keyboard(const Key& key, const keyboard_callback_t& callback,
                                        bool live = false) noexcept;

        public:
            /**
             * @brief Registers a callback for a specific mouse event type.
             *
             * This static method registers a callback function to handle a specific type of mouse event.
             *
             * @param type The type of the mouse event.
             * @param callback The callback function to handle the event.
             */
            static void listen_mouse(const MouseEventType& type, const mouse_callback_t& callback) noexcept;

        public:
            /**
             * @brief Registers a callback for text input events.
             *
             * This static method registers a callback function to handle text input events.
             *
             * @param callback The callback function to handle the event.
             */
            static void listen_text(const text_callback_t& callback) noexcept;

        private:
            /**
             * @brief Retrieves the unique instance of the Impl structure.
             *
             * @return A reference to the unique pointer of the Impl structure.
             */
            static std::unique_ptr<Impl>& getImpl() noexcept;

        private:
            /**
             * @brief Processes the events.
             *
             * This static method processes all the registered events.
             */
            static void process_events();
    };
}  // namespace H2DE
