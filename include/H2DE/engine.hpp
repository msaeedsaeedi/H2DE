#pragma once

#include <memory>
#include <string>

namespace H2DE
{
    class Engine
    {
        private:
            struct Impl;
            std::unique_ptr<Impl> m_impl;

        public:
            Engine();
            ~Engine();

            void init(const std::string& config_file);
            void run();

        public:
    };

}  // namespace H2DE
