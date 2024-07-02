#pragma once
#include <string>

#include "libconfig.h++"

namespace utils
{
    class read_config
    {
        public:
            read_config(const std::string &config_file);
            ~read_config();

            template <typename T>
            T get(const std::string &key);

        private:
            libconfig::Config cfg;
    };
}  // namespace utils

inline utils::read_config::read_config(const std::string &config_file) {
    try {
        cfg.readFile(config_file);
    } catch (const libconfig::FileIOException &fioex) {
        throw std::runtime_error("I/O error while reading file.");
    } catch (const libconfig::ParseException &pex) {
        throw std::runtime_error("Parse error at " +
                                 std::to_string(pex.getLine()) + ": " +
                                 pex.getError());
    }
}
inline utils::read_config::~read_config() {
    cfg.clear();
}
template <typename T>
inline T utils::read_config::get(const std::string &key) {
    T value;
    try {
        cfg.lookupValue(key, value);
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Setting not found: " + key);
    }
    return value;
}
