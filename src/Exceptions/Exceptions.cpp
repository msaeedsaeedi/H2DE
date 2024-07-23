#include "H2DE/Exceptions/Exceptions.hpp"

H2DE::H2DEException::H2DEException(const std::string &type, const std::string &message)
    : m_message("[H2DE]: " + type + "\n\t" + message) {
}

const char *H2DE::H2DEException::what() const noexcept {
    return m_message.c_str();
}