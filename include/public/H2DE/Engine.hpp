#pragma once

#include <memory>
#include <string>
#include <vector>

namespace H2DE
{
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
    };
}  // namespace H2DE