#pragma once

#include "H2DE/render_engine.hpp"

namespace H2DE
{
    class Scene
    {
        public:
            virtual ~Scene() = default;
            virtual void init() = 0;
            virtual void update(const float delta) = 0;
            virtual void render(const RenderEngine& render_engine) = 0;
    };
}  // namespace H2DE
