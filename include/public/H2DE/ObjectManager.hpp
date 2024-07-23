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
        private:
            friend class Scene;

            objects_t m_objects; /**< Collection of game objects */

            /**
             * @brief Default constructor.
             */
            ObjectManager() = default;

        public:
            /**
             * @brief Adds a new object with the specified ID.
             *
             * This method creates a new object with the given ID and adds it to the collection.
             *
             * @param id The unique identifier of the object.
             * @return A reference to the newly added object.
             */
            object_t& add_object(uint32_t id);

            /**
             * @brief Retrieves an object by its ID.
             *
             * This method returns a reference to the object with the specified ID.
             *
             * @param id The unique identifier of the object.
             * @return A reference to the object with the specified ID.
             */
            object_t& get_object(uint32_t id);

            /**
             * @brief Removes an object by its ID.
             *
             * This method removes the object with the specified ID from the collection.
             *
             * @param id The unique identifier of the object.
             */
            void remove_object(uint32_t id);

            /**
             * @brief Retrieves all objects.
             *
             * This method returns a reference to the collection of all objects.
             *
             * @return A reference to the vector of all objects.
             */
            objects_t& get_all();
    };
};  // namespace H2DE
