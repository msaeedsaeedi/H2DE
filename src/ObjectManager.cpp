#include "H2DE/ObjectManager.hpp"

#include <algorithm>

#include "H2DE/Exceptions/Exceptions.hpp"

H2DE::object_t& H2DE::ObjectManager::get_object(uint32_t id) {
    for (auto& object : m_objects) {
        if (object->get_id() == id) {
            return object;
        }
    }
    throw H2DE::H2DEException("ObjectManager", "Object not found");
}

void H2DE::ObjectManager::remove_object(uint32_t id) {
    auto it = std::find_if(m_objects.begin(), m_objects.end(),
                           [id](const std::shared_ptr<Object>& obj) { return obj->get_id() == id; });

    if (it != m_objects.end()) {
        m_objects.erase(it);
    } else {
        throw H2DE::H2DEException("ObjectManager", "Object not found");
    }
}

H2DE::objects_t& H2DE::ObjectManager::get_all() {
    return m_objects;
}