#pragma once

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
            static objects_t m_objects;

        public:
            static object_t& add_object(uint32_t id);
            static object_t& get_object(uint32_t id);
            static void remove_object(uint32_t id);
            static void clear_objects();
            static objects_t& get_objects();
    };
};  // namespace H2DE