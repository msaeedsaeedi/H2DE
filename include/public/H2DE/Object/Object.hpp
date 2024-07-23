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
        private:
            friend class ObjectManager;

            /**
             * @brief Constructs an Object with a specified ID.
             *
             * This constructor initializes the Object with a unique ID.
             *
             * @param _id The unique identifier of the object.
             */
            Object(uint32_t _id);

            uint32_t m_id;                /**< Unique identifier of the object */
            bool m_active;                /**< Indicates if the object is active */
            object_components components; /**< Tuple containing the object's components */

        public:
            /**
             * @brief Marks the object for destruction.
             */
            void destroy();

            /**
             * @brief Retrieves the unique ID of the object.
             *
             * @return The unique identifier of the object.
             */
            uint32_t get_id() const;

            /**
             * @brief Retrieves a reference to a component of the object.
             *
             * This template method returns a reference to the specified component type.
             *
             * @tparam T The type of the component.
             * @return A reference to the component.
             */
            template <typename T>
            T& get_component();

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

            /**
             * @brief Removes a component from the object.
             *
             * This template method removes the specified component type from the object.
             *
             * @tparam T The type of the component.
             */
            template <typename T>
            void remove_component();

            /**
             * @brief Checks if the object has a specific component.
             *
             * This template method checks if the object has the specified component type.
             *
             * @tparam T The type of the component.
             * @return True if the object has the component, false otherwise.
             */
            template <typename T>
            bool has_component();
    };

}  // namespace H2DE

template <typename T>
inline T& H2DE::Object::get_component() {
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
inline bool H2DE::Object::has_component() {
    return get_component<T>().has;
}
