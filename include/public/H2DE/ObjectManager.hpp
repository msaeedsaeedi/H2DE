#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "H2DE/Object/Object.hpp"

namespace H2DE
{
    /**
     * @typedef object_t
     * @brief Alias for a shared pointer to an Object.
     */
    using object_t = std::shared_ptr<Object>;

    /**
     * @typedef objects_t
     * @brief Alias for a vector of shared pointers to Objects.
     */
    using objects_t = std::vector<object_t>;

    /**
     * @class ObjectManager
     * @brief Manages the lifecycle of game objects.
     *
     * The ObjectManager class is responsible for creating, retrieving, and removing game objects.
     * It maintains a collection of objects and provides methods to manage them.
     */
    class ObjectManager
    {
        public:
            friend class Scene;

        private:
            /**
             * @brief Default constructor.
             */
            ObjectManager() = default;

        public:
            /**
             * @brief Default destructor.
             */
            ~ObjectManager() = default;

        public:
            /**
             * @brief Adds a new object with the specified object.
             *
             * This method creates a new object with the given object and adds it to the collection.
             *
             * @tparam T The object to add.
             * @return A reference to the newly added object.
             */
            template <class T, class... Args>
            object_t& add_object(Args&&... args);

        public:
            /**
             * @brief Retrieves an object by its ID.
             *
             * This method returns a reference to the object with the specified ID.
             *
             * @param id The unique identifier of the object.
             * @return A reference to the object with the specified ID.
             * @throws H2DE::H2DEException if the object with the specified ID does not exist.
             */
            object_t& get_object(uint32_t id);

        public:
            /**
             * @brief Removes an object by its ID.
             *
             * This method removes the object with the specified ID from the collection.
             *
             * @param id The unique identifier of the object.
             * @throws H2DE::H2DEException if the object with the specified ID does not exist.
             */
            void remove_object(uint32_t id);

        public:
            /**
             * @brief Retrieves all objects.
             *
             * This method returns a reference to the collection of all objects.
             *
             * @return A reference to the vector of all objects.
             */
            objects_t& get_all();

        private:
            objects_t m_objects; /**< Collection of game objects */
    };
};  // namespace H2DE

template <class T, class... Args>
inline H2DE::object_t& H2DE::ObjectManager::add_object(Args&&... args) {
    auto object = std::make_shared<T>(std::forward<Args>(args)...);
    object->m_id = m_objects.size();  //! USE ID MANAGEMENT
    m_objects.push_back(object);
    return m_objects.back();
}
