#pragma once

#include <memory>

#include "H2DE/object_manager.hpp"

namespace H2DE
{
    class Scene
    {
        public:
            friend class RenderEngine;

            Scene()
                : m_object_manager(
                      std::unique_ptr<ObjectManager>(new ObjectManager())) {
            }
            virtual ~Scene() = default;
            virtual void init() = 0;
            virtual void update(const float delta) = 0;

        protected:
            std::unique_ptr<ObjectManager> m_object_manager;
    };
}  // namespace H2DE
