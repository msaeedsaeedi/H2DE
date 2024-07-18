#pragma once

namespace H2DE
{
    namespace Component
    {
        struct Transform {
                Transform() = default;
                Transform(float x, float y) : position(x, y) {
                }

                std::pair<float, float> position;
                bool has = false;
        };
    }  // namespace Component
}  // namespace H2DE