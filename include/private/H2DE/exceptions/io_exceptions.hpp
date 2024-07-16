#pragma once

#include "H2DE/exceptions/exceptions.hpp"

namespace H2DE
{
    class IOException : public H2DEException
    {
        public:
            IOException(const std::string& file)
                : H2DEException("I/O Error", "Error reading file: " + file) {
            }
    };

    class ParseException : public H2DEException
    {
        public:
            ParseException(const std::string& file, int line,
                           const std::string& error)
                : H2DEException("Parsing Error",
                                "File: " + file +
                                    "\n\tLine: " + std::to_string(line) +
                                    "\n\tError: " + error) {
            }
            ParseException(const std::string& file, const std::string& error)
                : H2DEException("Parsing Error",
                                "File: " + file + "\n\tError: " + error) {
            }
    };
}  // namespace H2DE