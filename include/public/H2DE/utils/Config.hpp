#pragma once

#include <array>
#include <filesystem>
#include <libconfig.h++>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "H2DE/Exceptions/IOExceptions.hpp"

namespace H2DE
{
    class Config
    {
        public:
            Config(const std::string &config_file);
            ~Config();

            void set(const std::string &name, const int value);
            void set(const std::string &name, const float value);
            void set(const std::string &name, const long value);
            void set(const std::string &name, const bool value);
            void set(const std::string &name, const char *value);
            void set(const std::string &name, std::string value);

            template <typename T, std::size_t n>
            void set(const std::string &name, std::array<T, n>);

            template <typename T>
            T get(const std::string &key);

            template <typename T, std::size_t n>
            std::array<T, n> get(const std::string &key);

        private:
            void write();
            std::pair<libconfig::Setting &, std::string> getPath(
                const std::string &path);

        private:
            std::string config_file;
            libconfig::Config cfg;
    };

}  // namespace H2DE

inline H2DE::Config::Config(const std::string &config_file)
    : config_file(config_file) {
    try {
        if (std::filesystem::exists(config_file))
            cfg.readFile(config_file);
    } catch (const libconfig::FileIOException &fioex) {
        throw H2DE::IOException(config_file);
    } catch (const libconfig::ParseException &pex) {
        throw H2DE::ParseException(pex.getFile(), pex.getLine(),
                                   pex.getError());
    }
}

inline void H2DE::Config::set(const std::string &path, const int value) {
    auto [setting, key] = getPath(path);
    if (key.empty())
        setting.add(libconfig::Setting::Type::TypeInt) = value;
    else {
        if (setting.exists(key))
            setting[key] = value;
        else
            setting.add(key, libconfig::Setting::Type::TypeInt) = value;
    }
    write();
}

inline void H2DE::Config::set(const std::string &name, const float value) {
    auto [setting, key] = getPath(name);
    if (key.empty())
        setting.add(libconfig::Setting::Type::TypeFloat) = value;
    else {
        if (setting.exists(key))
            setting[key] = value;
        else
            setting.add(key, libconfig::Setting::Type::TypeFloat) = value;
    }
    write();
}

inline void H2DE::Config::set(const std::string &name, const long value) {
    auto [setting, key] = getPath(name);
    if (key.empty())
        setting.add(libconfig::Setting::Type::TypeInt64) = value;
    else {
        if (setting.exists(key))
            setting[key] = value;
        else
            setting.add(key, libconfig::Setting::Type::TypeInt64) = value;
    }
    write();
}

inline void H2DE::Config::set(const std::string &name, const bool value) {
    auto [setting, key] = getPath(name);
    if (key.empty())
        setting.add(libconfig::Setting::Type::TypeBoolean) = value;
    else {
        if (setting.exists(key))
            setting[key] = value;
        else
            setting.add(key, libconfig::Setting::Type::TypeBoolean) = value;
    }
    write();
}

inline void H2DE::Config::set(const std::string &name, const char *value) {
    auto [setting, key] = getPath(name);
    if (key.empty())
        setting.add(libconfig::Setting::Type::TypeString) = value;
    else {
        if (setting.exists(key))
            setting[key] = value;
        else
            setting.add(key, libconfig::Setting::Type::TypeString) = value;
    }
    write();
}

inline void H2DE::Config::set(const std::string &name, std::string value) {
    auto [setting, key] = getPath(name);
    if (key.empty())
        setting.add(libconfig::Setting::Type::TypeString) = value;
    else {
        if (setting.exists(key))
            setting[key] = value;
        else
            setting.add(key, libconfig::Setting::Type::TypeString) = value;
    }
    write();
}

template <typename T, std::size_t n>
inline void H2DE::Config::set(const std::string &name, std::array<T, n> array) {
    auto [setting, key] = getPath(name);
    libconfig::Setting &group =
        setting.add(key, libconfig::Setting::Type::TypeArray);
    for (const T &value : array) {
        this->set(name + ".#", value);
    }
    write();
}

template <typename T>
inline T H2DE::Config::get(const std::string &key) {
    try {
        libconfig::Setting &setting = cfg.lookup(key);
        return static_cast<T>(setting);
    } catch (const libconfig::SettingTypeException &stex) {
        throw H2DE::ParseException(
            this->config_file,
            "Invalid type for key { " + std::string(stex.getPath()) + " }");
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw H2DE::ParseException(
            this->config_file,
            "No such key { " + std::string(nfex.getPath()) + " }");
    }
}

template <typename T, std::size_t n>
inline std::array<T, n> H2DE::Config::get(const std::string &key) {
    try {
        libconfig::Setting &setting = cfg.lookup(key);
        std::array<T, n> array;
        for (size_t i = 0; i < n; ++i) {
            array[i] = static_cast<T>(setting[i]);
        }
        return array;
    } catch (const libconfig::SettingTypeException &stex) {
        throw H2DE::ParseException(
            this->config_file,
            "Invalid type for key { " + std::string(stex.getPath()) + " }");
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw H2DE::ParseException(
            this->config_file,
            "No such key { " + std::string(nfex.getPath()) + " }");
    }
}

inline void H2DE::Config::write() {
    try {
        cfg.writeFile(config_file);
    } catch (const libconfig::FileIOException &fioex) {
        throw H2DE::IOException(config_file, false);
    }
}

inline std::pair<libconfig::Setting &, std::string> H2DE::Config::getPath(
    const std::string &path) {
    libconfig::Setting &root = cfg.getRoot();

    std::istringstream iss(path);
    std::string token;
    libconfig::Setting *current = &root;

    std::vector<std::string> tokens;
    while (std::getline(iss, token, '.')) {
        tokens.push_back(token);
    }

    for (int i = 0; i < tokens.size() - 1; ++i) {
        const std::string &t = tokens[i];
        if (!current->exists(t)) {
            current = &current->add(t, libconfig::Setting::TypeGroup);
        } else {
            current = &(*current)[t];
        }
    }

    if (tokens.back() == "#")
        return {*current, ""};

    return {*current, tokens.back()};
}

inline H2DE::Config::~Config() {
    cfg.clear();
}