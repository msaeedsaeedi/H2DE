#include "H2DE/Exceptions/IOExceptions.hpp"

H2DE::IOException::IOException(const std::string &file,
                               const std::string &error)
    : H2DEException("I/O Error", "File: " + file + "\n\tError: " + error) {
}

H2DE::ParseException::ParseException(const std::string &file,
                                     const std::string &error)
    : H2DEException("Parsing Error", "File: " + file + "\n\tError: " + error) {
}