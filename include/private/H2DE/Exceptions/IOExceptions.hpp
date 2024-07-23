#pragma once

#include "H2DE/Exceptions/Exceptions.hpp"

namespace H2DE
{
    /**
     * @class IOException
     * @brief Exception class for handling I/O related errors.
     *
     * The IOException class provides a way to throw exceptions related to
     * input/output operations, such as file reading or writing errors. It
     * inherits from the H2DEException class.
     */
    class IOException : public H2DEException
    {
        public:
            /**
             * @brief Constructs an IOException with a file and error message.
             *
             * This constructor initializes the IOException with the name of the
             * file and a specific error message.
             *
             * @param file The name of the file where the error occurred.
             * @param error The detailed error message.
             */
            IOException(const std::string& file, const std::string& error);
    };

    /**
     * @class ParseException
     * @brief Exception class for handling parsing related errors.
     *
     * The ParseException class provides a way to throw exceptions related to
     * parsing operations, such as configuration file or data parsing errors. It
     * inherits from the H2DEException class.
     */
    class ParseException : public H2DEException
    {
        public:
            /**
             * @brief Constructs a ParseException with a file and error message.
             *
             * This constructor initializes the ParseException with the name of
             * the file and a specific error message.
             *
             * @param file The name of the file where the error occurred.
             * @param error The detailed error message.
             */
            ParseException(const std::string& file, const std::string& error);
    };
}  // namespace H2DE
