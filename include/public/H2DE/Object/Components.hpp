#pragma once
#include <string>
#include <utility>

namespace H2DE
{
    class RenderEngine;

    namespace Component
    {
        class Transform
        {
            public:
                Transform() = default;
                Transform(float x, float y) : position(x, y) {
                }

                std::pair<float, float> position;
                std::pair<float, float> scale{1.0f, 1.0f};
                float rotation = 0.0f;

                bool has = false;
        };

        class Sprite
        {
            private:
                friend class H2DE::RenderEngine;

            public:
                Sprite() = default;
                Sprite(const std::string& url);

                std::pair<float, float> origin;
                std::pair<float, float>
                    size;  // ! BUG: User can change this value

                bool has = false;

            private:
                uint32_t m_asset_id;
        };
    }  // namespace Component
}  // namespace H2DE