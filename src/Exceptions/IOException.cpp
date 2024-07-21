#include "H2DE/Exceptions/IOExceptions.hpp"

H2DE::IOException::IOException(const std::string &file)
    : H2DEException("I/O Error", "Error reading file: " + file) {
}

H2DE::ParseException::ParseException(const std::string &file, int line,
                                     const std::string &error)
    : H2DEException("Parsing Error", "File: " + file +
                                         "\n\tLine: " + std::to_string(line) +
                                         "\n\tError: " + error) {
}

H2DE::ParseException::ParseException(const std::string &file,
                                     const std::string &error)
    : H2DEException("Parsing Error", "File: " + file + "\n\tError: " + error) {
}