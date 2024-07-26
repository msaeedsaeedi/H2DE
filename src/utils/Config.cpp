#include "H2DE/utils/Config.hpp"

#include <fstream>
#include <sstream>

#include "H2DE/Exceptions/IOExceptions.hpp"

namespace H2DE
{
    Config::Config(const std::string &config_file, bool create) : config_file(config_file) {
        validateFileExtension(config_file);
        if (create)
            saveConfig();
        else
            loadConfig();
    }

    void Config::validateFileExtension(const std::string &config_file) {
        if (config_file.find(".json") == std::string::npos)
            throw IOException(config_file, "Invalid file extension");
    }

    Config::~Config() {
        saveConfig();
    }

    void Config::loadConfig() {
        std::ifstream input(config_file);
        if (input.is_open()) {
            try {
                input >> cfg;
            } catch (const nlohmann::json::parse_error &e) {
                throw ParseException(config_file, e.what());
            }
            input.close();
        } else {
            throw IOException(config_file, "Can't open file");
        }
    }

    void Config::saveConfig() const {
        std::ofstream output(config_file);
        if (output.is_open()) {
            try {
                output << cfg.dump(4);
            } catch (const nlohmann::json::type_error &e) {
                throw ParseException(config_file, "Type error: " + std::string(e.what()));
            } catch (const nlohmann::json::out_of_range &e) {
                throw ParseException(config_file, "Out of range error: " + std::string(e.what()));
            }
            output.close();
        } else {
            throw IOException(config_file, "Can't save file");
        }
    }

    void Config::set(const std::string &name, const json &value) {
        json *target = getNestedJson(name);
        *target = value;
    }

    json Config::get(const std::string &key) const {
        const json *target = getNestedJson(key);
        return *target;
    }

    json *Config::getNestedJson(const std::string &path) {
        json *current = &cfg;
        std::istringstream iss(path);
        std::string token;
        while (std::getline(iss, token, '.')) {
            if (current->contains(token)) {
                current = &(*current)[token];
            } else {
                (*current)[token] = json();
                current = &(*current)[token];
            }
        }
        return current;
    }

    const json *Config::getNestedJson(const std::string &path) const {
        const json *current = &cfg;
        std::istringstream iss(path);
        std::string token;
        while (std::getline(iss, token, '.')) {
            if (current->contains(token)) {
                current = &(*current)[token];
            } else {
                throw ParseException(config_file, "Key not found { " + path + " }");
            }
        }
        return current;
    }

}  // namespace H2DE
