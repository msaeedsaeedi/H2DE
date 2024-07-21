#pragma once
#include <string>

#include "H2DE/Exceptions/IOExceptions.hpp"
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
            std::string config_file;
    };
}  // namespace utils

inline utils::read_config::read_config(const std::string &config_file)
    : config_file(config_file) {
    try {
        cfg.readFile(config_file);
    } catch (const libconfig::FileIOException &fioex) {
        throw H2DE::IOException(config_file);
    } catch (const libconfig::ParseException &pex) {
        throw H2DE::ParseException(pex.getFile(), pex.getLine(),
                                   pex.getError());
    }
}
inline utils::read_config::~read_config() {
    cfg.clear();
}
template <typename T>
inline T utils::read_config::get(const std::string &key) {
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
