#pragma once

#include <memory>

#include "H2DE/object_manager.hpp"

namespace H2DE
{
    class Scene
    {
        private:
            float m_delta = 0.0f;

        public:
            friend class RenderEngine;
            friend class Engine;

            Scene()
                : m_object_manager(
                      std::unique_ptr<ObjectManager>(new ObjectManager())) {
            }
            virtual ~Scene() = default;
            virtual void init() = 0;
            virtual void update() = 0;
            const float get_delta() const noexcept {
                return m_delta;
            }

        protected:
            std::unique_ptr<ObjectManager> m_object_manager;
    };
}  // namespace H2DE
