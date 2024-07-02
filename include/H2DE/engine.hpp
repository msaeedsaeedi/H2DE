#pragma once

#include <memory>
#include <string>

namespace H2DE
{
    class Game;

    class Engine
    {
        private:
            struct Impl;
            std::unique_ptr<Impl> m_impl;

        public:
            Engine();
            ~Engine();

            void init(const std::string& config_file);
            void set_game(const std::shared_ptr<Game>& game);
            void run();

        private:
            void validate_requirements();
    };
}  // namespace H2DE
