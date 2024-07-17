#pragma once

#include <memory>
#include <string>
#include <vector>

#include "H2DE/scene.hpp"
#include "H2DE/object.hpp"

namespace H2DE
{
    using Objects_t = std::vector<std::unique_ptr<Object>>;
    class RenderEngine;
    class Engine
    {
        friend class RenderEngine;
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
