#pragma once

namespace H2DE
{
    class Scene
    {
        public:
            virtual ~Scene() = default;
            virtual void init() = 0;
            virtual void update(const float delta) = 0;
    };
}  // namespace H2DE
