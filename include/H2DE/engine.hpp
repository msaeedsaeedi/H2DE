#pragma once

#include <memory>
#include <string>

#include "H2DE/scene.hpp"

namespace H2DE
{
    class Engine
    {
        private:
            struct Impl;
            static std::unique_ptr<Impl> m_impl;

        public:
            Engine();
            ~Engine();

            static void init(const std::string& config_file);
            static void run();
            static void exit();

        private:
            static void process_events();
    };
}  // namespace H2DE
