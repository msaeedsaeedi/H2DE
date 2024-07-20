#pragma once

#include <cstdint>
#include <tuple>

#include "H2DE/components.hpp"

namespace H2DE
{
    typedef std::tuple<Component::Transform, Component::Sprite>
        object_components;

    class Object
    {
        private:
            friend class ObjectManager;

            uint32_t m_id;
            bool m_active;
            object_components components;

            Object(uint32_t _id) : m_id(_id) {
                m_active = true;
            }

        public:
            void destroy() {
                m_active = false;
            }

            uint32_t get_id() const {
                return this->m_id;
            }

            template <typename T>
            T& get_component() {
                return std::get<T>(components);
            }

            template <typename T, typename... Args>
            T& add_component(Args&&... args) {
                auto& component = get_component<T>();
                component = T{std::forward<Args>(args)...};
                component.has = true;
                return component;
            }

            template <typename T>
            void remove_component() {
                get_component<T>() = T();
            }

            template <typename T>
            bool has_component() {
                return get_component<T>().has;
            }
    };

}  // namespace H2DE
