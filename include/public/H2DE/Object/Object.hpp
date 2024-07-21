#pragma once

#include <cstdint>
#include <tuple>

#include "H2DE/Object/Components.hpp"

namespace H2DE
{
    typedef std::tuple<Component::Transform, Component::Sprite>
        object_components;

    class Object
    {
        private:
            friend class ObjectManager;

            Object(uint32_t _id);

            uint32_t m_id;
            bool m_active;
            object_components components;

        public:
            void destroy();
            uint32_t get_id() const;

            template <typename T>
            T& get_component();

            template <typename T, typename... Args>
            T& add_component(Args&&... args);

            template <typename T>
            void remove_component();

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