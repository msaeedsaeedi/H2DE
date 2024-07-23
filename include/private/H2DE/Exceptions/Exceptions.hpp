#pragma once

#include <exception>
#include <string>

namespace H2DE
{
    /**
     * @class H2DEException
     * @brief Custom exception class for handling exceptions specific to the
     * H2DE engine.
     *
     * The H2DEException class provides a way to throw exceptions with a
     * specific type and message related to the H2DE engine. It inherits from
     * the standard std::exception class.
     */
    class H2DEException : public std::exception
    {
        public:
            /**
             * @brief Constructs an H2DEException with a type and message.
             *
             * This constructor initializes the H2DEException with a specific
             * type and message.
             *
             * @param type The type of the exception.
             * @param message The detailed message of the exception.
             */
            H2DEException(const std::string& type, const std::string& message);

            /**
             * @brief Retrieves the exception message.
             *
             * This method returns the detailed message of the exception.
             *
             * @return A C-style character string describing the exception.
             */
            virtual const char* what() const noexcept override;

        private:
            /**
             * @brief The detailed message of the exception.
             */
            std::string m_message;
    };
}  // namespace H2DE
