#pragma once

#include <memory>
#include <string>
#include <vector>

namespace H2DE
{
    /**
     * @class Engine
     * @brief Manages the initialization, running, and exiting of the game engine.
     *
     * The Engine class is responsible for the overall control of the game engine, including
     * initializing with a configuration file, running the main game loop, and handling exit procedures.
     * This class follows the singleton pattern to ensure a single instance of the engine.
     */
    class Engine
    {
        private:
            /**
             * @struct Impl
             * @brief Internal implementation structure for the Engine class.
             */
            struct Impl;

            /**
             * @brief Retrieves the unique instance of the Impl structure.
             *
             * @return A reference to the unique pointer of the Impl structure.
             */
            static std::unique_ptr<Impl>& getImpl() noexcept;

        public:
            /**
             * @brief Destructor.
             */
            ~Engine();

            /**
             * @brief Initializes the engine with the specified configuration file.
             *
             * This static method initializes the engine using settings from the provided configuration file.
             *
             * @param config_file The path to the configuration file.
             */
            static void init(const std::string& config_file);

            /**
             * @brief Runs the main game loop.
             *
             * This static method starts and runs the main game loop.
             */
            static void run();

            /**
             * @brief Exits the engine.
             *
             * This static method handles the exit procedures for the engine.
             */
            static void exit();

        private:
            /**
             * @brief Deleted default constructor to prevent instantiation.
             */
            Engine() = delete;

            /**
             * @brief Deleted copy constructor to prevent copying.
             */
            Engine(const Engine&) = delete;

            /**
             * @brief Deleted assignment operator to prevent assignment.
             *
             * @return Reference to the Engine instance.
             */
            Engine& operator=(const Engine&) = delete;
    };
}  // namespace H2DE
