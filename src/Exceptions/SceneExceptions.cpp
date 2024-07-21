#include "H2DE/Exceptions/SceneExceptions.hpp"

H2DE::SceneException::SceneException(const std::string &message)
    : H2DE::H2DEException("Scene Exception", "Error: " + message) {
}