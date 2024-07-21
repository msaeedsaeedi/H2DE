#pragma once

#include <memory>

#include "H2DE/ObjectManager.hpp"

namespace H2DE
{
    class Scene
    {
        private:
            float m_delta = 0.0f;

        public:
            friend class RenderEngine;
            friend class Engine;

            Scene();
            virtual ~Scene() = default;
            virtual void init() = 0;
            virtual void update() = 0;
            const float get_delta() const noexcept;

        protected:
            std::unique_ptr<ObjectManager> m_object_manager;
    };
}  // namespace H2DE
