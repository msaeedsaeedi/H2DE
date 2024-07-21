#pragma once
#include "H2DE/Exceptions/Exceptions.hpp"

namespace H2DE
{
    class SceneException : public H2DE::H2DEException
    {
        public:
            SceneException(const std::string& message)
                : H2DE::H2DEException("Scene Exception", "Error: " + message) {
            }
    };
}  // namespace H2DE