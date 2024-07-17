#pragma once

#include <memory>
#include <string>
#include <vector>

#include "H2DE/object.hpp"

namespace H2DE
{
    using Objects_t = std::vector<std::unique_ptr<Object>>;
    class Engine
    {
        private:
            struct Impl;
            static std::unique_ptr<Impl>& getImpl() noexcept;

        public:
            ~Engine();

            static void init(const std::string& config_file);
            static void run();
            static void exit();

        private:
            Engine() = delete;
            Engine(const Engine&) = delete;
            Engine& operator=(const Engine&) = delete;

            static void process_events();
    };
}  // namespace H2DE
