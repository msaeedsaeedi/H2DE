#pragma once
#include <string>

#include "H2DE/utils/nlohmann/json.hpp"

using namespace nlohmann;

namespace H2DE
{
    /**
     * @class Config
     * @brief Handles loading, saving, and manipulating configuration files.
     *
     * The Config class provides methods to load and save configuration settings from/to a JSON file.
     * It also allows setting and getting configuration values using JSON paths.
     */
    class Config
    {
        public:
            /**
             * @brief Constructs a Config object with a specified configuration file.
             *
             * This constructor initializes the Config object and optionally creates a new configuration
             * file if it doesn't exist.
             *
             * @param config_file The path to the configuration file.
             * @param create If true, creates a new configuration file if it doesn't exist.
             */
            Config(const std::string &config_file, bool create = false);

            /**
             * @brief Destructor.
             */
            ~Config();

            /**
             * @brief Sets a configuration value.
             *
             * This method sets the value of a configuration setting identified by the provided name.
             *
             * @param name The name of the configuration setting.
             * @param value The value to set for the configuration setting.
             */
            void set(const std::string &name, const json &value);

            /**
             * @brief Gets a configuration value.
             *
             * This method retrieves the value of a configuration setting identified by the provided key.
             *
             * @param key The key of the configuration setting to retrieve.
             * @return The value of the configuration setting.
             */
            json get(const std::string &key) const;

        private:
            /**
             * @brief Validates the file extension of the configuration file.
             *
             * This method checks if the configuration file has a valid extension.
             *
             * @param config_file The path to the configuration file.
             * @throws std::invalid_argument if the file extension is not valid.
             */
            void validateFileExtension(const std::string &config_file);

            /**
             * @brief Loads the configuration file.
             *
             * This method loads the configuration settings from the file.
             */
            void loadConfig();

            /**
             * @brief Saves the configuration file.
             *
             * This method saves the current configuration settings to the file.
             */
            void saveConfig() const;

            /**
             * @brief Retrieves a nested JSON object by path.
             *
             * This method retrieves a nested JSON object using a dot-separated path.
             *
             * @param path The dot-separated path to the nested JSON object.
             * @return A pointer to the nested JSON object.
             */
            json *getNestedJson(const std::string &path);

            /**
             * @brief Retrieves a nested JSON object by path (const version).
             *
             * This method retrieves a nested JSON object using a dot-separated path.
             *
             * @param path The dot-separated path to the nested JSON object.
             * @return A const pointer to the nested JSON object.
             */
            const json *getNestedJson(const std::string &path) const;

        private:
            std::string config_file; /**< The path to the configuration file */
            json cfg;                /**< The JSON object representing the configuration settings */
    };
}  // namespace H2DE
