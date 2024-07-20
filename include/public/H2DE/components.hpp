#pragma once
#include <utility>

namespace H2DE
{
    class RenderEngine;

    namespace Component
    {
        struct Transform {
                Transform() = default;
                Transform(float x, float y) : position(x, y) {
                }

                std::pair<float, float> position;
                bool has = false;
        };

        class Sprite
        {
            private:
                friend class H2DE::RenderEngine;

            public:
                Sprite() = default;
                Sprite(const std::string& url);

                std::pair<float, float> scale{1.0f, 1.0f};
                bool has = false;

            private:
                uint32_t asset_id;
        };
    }  // namespace Component
}  // namespace H2DE