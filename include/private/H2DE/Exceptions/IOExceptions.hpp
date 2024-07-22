#pragma once

#include "H2DE/Exceptions/Exceptions.hpp"

namespace H2DE
{
    class IOException : public H2DEException
    {
        public:
            IOException(const std::string& file, const std::string& error);
    };

    class ParseException : public H2DEException
    {
        public:
            ParseException(const std::string& file, const std::string& error);
    };
}  // namespace H2DE