#pragma once

#include <exception>
#include <string>

namespace H2DE
{
    class H2DEException : public std::exception
    {
        public:
            H2DEException(const std::string& type, const std::string& message)
                : m_message("[H2DE]: " + type + "\n\t" + message) {
            }

            virtual const char* what() const noexcept override {
                return m_message.c_str();
            }

        private:
            std::string m_message;
    };
}  // namespace H2DE