#include "H2DE/utils/Config.hpp"

#include <gtest/gtest.h>

#include <filesystem>

#include "H2DE/Exceptions/IOExceptions.hpp"
#include "H2DE/utils/Config.hpp"

class ConfigTest : public ::testing::Test
{
    protected:
        H2DE::Config* config;

        void SetUp() override {
            std::filesystem::create_directory("assets/configuration");
            config = new H2DE::Config("assets/configuration/config.json", true);
        }

        void TearDown() override {
            delete config;
            std::filesystem::remove_all("assets/configuration");
        }
};

TEST_F(ConfigTest, init) {
    EXPECT_THROW(H2DE::Config config("assets/configuration/config_init.json"),
                 H2DE::IOException);
    EXPECT_NO_THROW(
        H2DE::Config config("assets/configuration/config_init.json", true));
    EXPECT_NO_THROW(
        H2DE::Config config("assets/configuration/config_init.json", true));
}

TEST_F(ConfigTest, scalar) {
    config->set("data.int", 32);
    config->set("data.float", 23.0f);
    config->set("data.string", "Hello, World!");
    config->set("data.bool", true);

    EXPECT_EQ(config->get("data.int"), 32);
    EXPECT_FLOAT_EQ(config->get("data.float"), 23.0f);
    EXPECT_EQ(config->get("data.string"), "Hello, World!");
    EXPECT_EQ(config->get("data.bool"), true);
}

TEST_F(ConfigTest, scalar_update) {
    H2DE::Config config("assets/configuration/config.json");
    config.set("data.int", 32);
    config.set("data.float", 23.0f);
    config.set("data.string", "Hello, World!");
    config.set("data.bool", true);

    config.set("data.int", 64);
    config.set("data.float", 46.0f);
    config.set("data.string", "World, Hello!");
    config.set("data.bool", false);

    EXPECT_EQ(config.get("data.int"), 64);
    EXPECT_FLOAT_EQ(config.get("data.float"), 46.0f);
    EXPECT_EQ(config.get("data.string"), "World, Hello!");
    EXPECT_EQ(config.get("data.bool"), false);
}

TEST_F(ConfigTest, array) {
    H2DE::Config config("assets/configuration/config.json");
    config.set("array.int", std::array<int, 3>{1, 2, 3});
    config.set("array.float", std::array<float, 3>{1.0f, 2.0f, 3.0f});
    config.set("array.string",
               std::array<std::string, 3>{"Hello", "World", "!"});
    config.set("array.bool", std::array<bool, 3>{true, false, true});

    EXPECT_EQ(config.get("array.int"), (std::array<int, 3>{1, 2, 3}));
    EXPECT_EQ(config.get("array.float"),
              (std::array<float, 3>{1.0f, 2.0f, 3.0f}));
    EXPECT_EQ(config.get("array.string"),
              (std::array<std::string, 3>{"Hello", "World", "!"}));
    EXPECT_EQ(config.get("array.bool"),
              (std::array<bool, 3>{true, false, true}));
}

TEST_F(ConfigTest, array_update) {
    H2DE::Config config("assets/configuration/config.json");
    config.set("array.int", std::array<int, 3>{1, 2, 3});
    config.set("array.float", std::array<float, 3>{1.0f, 2.0f, 3.0f});
    config.set("array.string",
               std::array<std::string, 3>{"Hello", "World", "!"});
    config.set("array.bool", std::array<bool, 3>{true, false, true});

    config.set("array.int", std::array<int, 3>{4, 5, 6});
    config.set("array.float", std::array<float, 3>{4.0f, 5.0f, 6.0f});
    config.set("array.string",
               std::array<std::string, 3>{"World", "Hello", "!"});
    config.set("array.bool", std::array<bool, 3>{false, true, false});

    EXPECT_EQ(config.get("array.int"), (std::array<int, 3>{4, 5, 6}));
    EXPECT_EQ(config.get("array.float"),
              (std::array<float, 3>{4.0f, 5.0f, 6.0f}));
    EXPECT_EQ(config.get("array.string"),
              (std::array<std::string, 3>{"World", "Hello", "!"}));
    EXPECT_EQ(config.get("array.bool"),
              (std::array<bool, 3>{false, true, false}));
}

TEST_F(ConfigTest, object) {
    H2DE::Config config("assets/configuration/config.json");
    config.set("object.int", json{{"a", 1}, {"b", 2}, {"c", 3}});
    config.set("object.float", json{{"a", 1.0f}, {"b", 2.0f}, {"c", 3.0f}});
    config.set("object.string",
               json{{"a", "Hello"}, {"b", "World"}, {"c", "!"}});
    config.set("object.bool", json{{"a", true}, {"b", false}, {"c", true}});

    EXPECT_EQ(config.get("object.int"), json({{"a", 1}, {"b", 2}, {"c", 3}}));
    EXPECT_EQ(config.get("object.float"),
              json({{"a", 1.0f}, {"b", 2.0f}, {"c", 3.0f}}));
    EXPECT_EQ(config.get("object.string"),
              json({{"a", "Hello"}, {"b", "World"}, {"c", "!"}}));
    EXPECT_EQ(config.get("object.bool"),
              json({{"a", true}, {"b", false}, {"c", true}}));
}

TEST_F(ConfigTest, object_update) {
    config->set("object.int", json{{"a", 1}, {"b", 2}, {"c", 3}});
    config->set("object.float", json{{"a", 1.0f}, {"b", 2.0f}, {"c", 3.0f}});
    config->set("object.string",
                json{{"a", "Hello"}, {"b", "World"}, {"c", "!"}});
    config->set("object.bool", json{{"a", true}, {"b", false}, {"c", true}});

    config->set("object.int", json{{"a", 4}, {"b", 5}, {"c", 6}});
    config->set("object.float", json{{"a", 4.0f}, {"b", 5.0f}, {"c", 6.0f}});
    config->set("object.string",
                json{{"a", "World"}, {"b", "Hello"}, {"c", "!"}});
    config->set("object.bool", json{{"a", false}, {"b", true}, {"c", false}});

    EXPECT_EQ(config->get("object.int"), json({{"a", 4}, {"b", 5}, {"c", 6}}));
    EXPECT_EQ(config->get("object.float"),
              json({{"a", 4.0f}, {"b", 5.0f}, {"c", 6.0f}}));
    EXPECT_EQ(config->get("object.string"),
              json({{"a", "World"}, {"b", "Hello"}, {"c", "!"}}));
    EXPECT_EQ(config->get("object.bool"),
              json({{"a", false}, {"b", true}, {"c", false}}));
}