#pragma once

#include <cstdint>
#include <tuple>

#include "H2DE/Object/Components.hpp"

namespace H2DE
{
    /**
     * @typedef object_components
     * @brief Alias for a tuple containing the common components of an object.
     */
    using object_components = std::tuple<Component::Transform, Component::Sprite>;

    /**
     * @class Object
     * @brief Represents a game object with a unique ID and various components.
     *
     * The Object class manages a game object, providing functionality to add, remove,
     * and access components. Each game object can have multiple components attached to it,
     * which define its behavior and characteristics.
     */
    class Object
    {
        public:
            friend class ObjectManager;

        protected:
            /**
             * @brief Default constructor.
             *
             * This constructor initializes the Object.
             */
            Object();

        public:
            /**
             * @brief Default destructor.
             */
            ~Object() = default;

        public:
            /**
             * @brief Updates the object.
             *
             * This method updates the object with the specified delta time.
             *
             * @param delta The time elapsed since the last update.
             */
            virtual void update(const float delta) = 0;

        public:
            /**
             * @brief Marks the object for destruction.
             */
            void destroy() noexcept;

        public:
            /**
             * @brief Retrieves the unique ID of the object.
             *
             * @return The unique identifier of the object.
             */
            uint32_t get_id() const noexcept;

        public:
            /**
             * @brief Retrieves a reference to a component of the object.
             *
             * This template method returns a reference to the specified component type.
             *
             * @tparam T The type of the component.
             * @return A reference to the component.
             */
            template <typename T>
            T& get_component() noexcept;

        public:
            /**
             * @brief Adds a component to the object.
             *
             * This template method adds a component of the specified type to the object,
             * forwarding the provided arguments to the component's constructor.
             *
             * @tparam T The type of the component.
             * @tparam Args The types of the arguments.
             * @param args The arguments to forward to the component's constructor.
             * @return A reference to the added component.
             */
            template <typename T, typename... Args>
            T& add_component(Args&&... args);

        public:
            /**
             * @brief Removes a component from the object.
             *
             * This template method removes the specified component type from the object.
             *
             * @tparam T The type of the component.
             */
            template <typename T>
            void remove_component();

        public:
            /**
             * @brief Checks if the object has a specific component.
             *
             * This template method checks if the object has the specified component type.
             *
             * @tparam T The type of the component.
             * @return True if the object has the component, false otherwise.
             */
            template <typename T>
            bool has_component() noexcept;

        private:
            uint32_t m_id;                /**< Unique identifier of the object */
            bool m_active;                /**< Indicates if the object is active */
            object_components components; /**< Tuple containing the object's components */
    };

}  // namespace H2DE

template <typename T>
inline T& H2DE::Object::get_component() noexcept {
    return std::get<T>(components);
}

template <typename T, typename... Args>
inline T& H2DE::Object::add_component(Args&&... args) {
    auto& component = get_component<T>();
    component = T{std::forward<Args>(args)...};
    component.has = true;
    return component;
}

template <typename T>
inline void H2DE::Object::remove_component() {
    get_component<T>() = T();
}

template <typename T>
inline bool H2DE::Object::has_component() noexcept {
    return get_component<T>().has;
}
