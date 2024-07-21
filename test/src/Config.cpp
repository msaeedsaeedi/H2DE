#include "H2DE/utils/Config.hpp"

#include <gtest/gtest.h>

#include <filesystem>

class WriteConfigTest : public ::testing::Test
{
    protected:
        void SetUp() override {
            std::filesystem::create_directory("assets/configuration");
        }

        void TearDown() override {
            std::filesystem::remove_all("assets/configuration");
        }
};

TEST_F(WriteConfigTest, init) {
    EXPECT_NO_THROW(H2DE::Config config("assets/configuration/config.cfg"));
    EXPECT_NO_THROW(H2DE::Config config("assets/configuration/config.cfg"));
}

TEST_F(WriteConfigTest, scalar) {
    H2DE::Config config("assets/configuration/config.cfg");
    config.set("data.int", 32);
    config.set("data.float", 23.0f);
    config.set("data.string", "Hello, World!");
    config.set("data.bool", true);

    EXPECT_FLOAT_EQ(config.get<float>("data.float"), 23.0f);
    EXPECT_EQ(config.get<int>("data.int"), 32);
    EXPECT_STREQ(config.get<std::string>("data.string").c_str(),
                 "Hello, World!");
    EXPECT_EQ(config.get<bool>("data.bool"), true);
}

TEST_F(WriteConfigTest, scalar_update) {
    H2DE::Config config("assets/configuration/config.cfg");
    config.set("data.int", 32);
    config.set("data.float", 23.0f);
    config.set("data.string", "Hello, World!");
    config.set("data.bool", true);

    config.set("data.int", 64);
    config.set("data.float", 46.0f);
    config.set("data.string", "World, Hello!");
    config.set("data.bool", false);

    EXPECT_FLOAT_EQ(config.get<float>("data.float"), 46.0f);
    EXPECT_EQ(config.get<int>("data.int"), 64);
    EXPECT_STREQ(config.get<std::string>("data.string").c_str(),
                 "World, Hello!");
    EXPECT_EQ(config.get<bool>("data.bool"), false);
}

TEST_F(WriteConfigTest, array) {
    H2DE::Config config("assets/configuration/config.cfg");
    config.set("array.int", std::array<int, 3>{1, 2, 3});
    config.set("array.float", std::array<float, 3>{1.0f, 2.0f, 3.0f});
    config.set("array.string",
               std::array<std::string, 3>{"Hello", "World", "!"});
    config.set("array.bool", std::array<bool, 3>{true, false, true});

    std::array<int, 3> data = config.get<int, 3>("array.int");
    std::array<float, 3> data2 = config.get<float, 3>("array.float");
    std::array<std::string, 3> data3 =
        config.get<std::string, 3>("array.string");
    std::array<bool, 3> data4 = config.get<bool, 3>("array.bool");

    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);

    EXPECT_FLOAT_EQ(data2[0], 1.0f);
    EXPECT_FLOAT_EQ(data2[1], 2.0f);
    EXPECT_FLOAT_EQ(data2[2], 3.0f);

    EXPECT_STREQ(data3[0].c_str(), "Hello");
    EXPECT_STREQ(data3[1].c_str(), "World");
    EXPECT_STREQ(data3[2].c_str(), "!");

    EXPECT_EQ(data4[0], true);
    EXPECT_EQ(data4[1], false);
    EXPECT_EQ(data4[2], true);
}