#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "H2DE/object.hpp"

namespace H2DE
{
    using object_t = std::shared_ptr<Object>;
    using objects_t = std::vector<object_t>;
    class ObjectManager
    {
        private:
            friend class Scene;

            objects_t m_objects;
            ObjectManager() = default;

        public:
            object_t& add_object(uint32_t id);
            object_t& get_object(uint32_t id);
            void remove_object(uint32_t id);
            objects_t& get_all();
    };
};  // namespace H2DE