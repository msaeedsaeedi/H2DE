#include "H2DE/Engine.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <filesystem>

#include "H2DE/utils/Config.hpp"

class EngineTest : public ::testing::Test
{
    protected:
        void SetUp() override {
            std::filesystem::create_directory("configurations");
            H2DE::Config config("configurations/config.json", true);
            config.set("window.width", 800);
            config.set("window.height", 600);
            config.set("window.title", "Test");
            config.set("window.fullscreen", false);
            config.set("window.fps", 60);
        }

        void TearDown() override {
            std::filesystem::remove_all("configurations");
        }
};

TEST_F(EngineTest, Init) {
    EXPECT_NO_THROW(H2DE::Engine::init("configurations/config.json"));
}