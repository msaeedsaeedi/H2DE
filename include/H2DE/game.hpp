#pragma once

#include <memory>

namespace H2DE
{

    class Engine;

    class Game
    {
        private:
            std::shared_ptr<Engine> m_engine;

        public:
            Game();
            virtual ~Game() = default;

            virtual void update() = 0;
    };

}  // namespace H2DE
