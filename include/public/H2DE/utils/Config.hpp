#pragma once
#include <string>

#include "H2DE/utils/nlohmann/json.hpp"

using namespace nlohmann;

namespace H2DE
{
    class Config
    {
        public:
            Config(const std::string &config_file, bool create = false);
            void validateFileExtension(const std::string &config_file);
            ~Config();

            void set(const std::string &name, const json &value);
            json get(const std::string &key) const;

        private:
            std::string config_file;
            json cfg;

            void loadConfig();
            void saveConfig() const;

            json *getNestedJson(const std::string &path);
            const json *getNestedJson(const std::string &path) const;
    };
}  // namespace H2DE
