#pragma once
#include "H2DE/Exceptions/Exceptions.hpp"

namespace H2DE
{
    /**
     * @class SceneException
     * @brief Exception class for handling scene-related errors.
     *
     * The SceneException class provides a way to throw exceptions related to
     * scene management, such as errors occurring during scene loading or
     * updating. It inherits from the H2DEException class.
     */
    class SceneException : public H2DE::H2DEException
    {
        public:
            /**
             * @brief Constructs a SceneException with an error message.
             *
             * This constructor initializes the SceneException with a specific
             * error message.
             *
             * @param message The detailed error message.
             */
            SceneException(const std::string& message);
    };
}  // namespace H2DE
