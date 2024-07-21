#include "H2DE/SceneManager.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <unordered_map>

#include "H2DE/Exceptions/SceneExceptions.hpp"
#include "H2DE/Scene/Scene.hpp"

namespace H2DE
{
    // Mock Scene class for testing
    class MockScene : public Scene
    {
        public:
            MockScene() {
            }
            void init() override {
            }
            void update() override {
            }
    };

    // Test Fixture for SceneManager
    class SceneManagerTest : public ::testing::Test
    {
        protected:
            void SetUp() override {
                SceneManager::add_scene("Scene1",
                                        std::make_shared<MockScene>());
                SceneManager::add_scene("Scene2",
                                        std::make_shared<MockScene>());
            }

            void TearDown() override {
                SceneManager::remove_scene("Scene1");
                SceneManager::remove_scene("Scene2");
            }
    };

    TEST_F(SceneManagerTest, AddScene) {
        auto scene3 = std::make_shared<MockScene>();
        SceneManager::add_scene("Scene3", scene3);
        auto retrievedScene = SceneManager::get_scene("Scene3");
        EXPECT_EQ(scene3, retrievedScene);
        SceneManager::remove_scene("Scene3");
    }

    TEST_F(SceneManagerTest, ChangeScene) {
        SceneManager::change_scene("Scene1");
        auto currentScene = SceneManager::get_current_scene();
        EXPECT_EQ(SceneManager::get_scene("Scene1"), currentScene);

        SceneManager::change_scene("Scene2");
        currentScene = SceneManager::get_current_scene();
        EXPECT_EQ(SceneManager::get_scene("Scene2"), currentScene);
    }

    TEST_F(SceneManagerTest, RemoveScene) {
        SceneManager::remove_scene("Scene1");
        EXPECT_THROW(SceneManager::get_scene("Scene1"), H2DE::SceneException);
        SceneManager::add_scene("Scene1", std::make_shared<MockScene>());

        SceneManager::remove_scene("Scene2");
        EXPECT_THROW(SceneManager::get_scene("Scene2"), H2DE::SceneException);
        SceneManager::add_scene("Scene2", std::make_shared<MockScene>());
    }

    TEST_F(SceneManagerTest, GetScene) {
        auto scene1 = SceneManager::get_scene("Scene1");
        EXPECT_NE(nullptr, scene1);

        auto scene2 = SceneManager::get_scene("Scene2");
        EXPECT_NE(nullptr, scene2);
    }

    TEST_F(SceneManagerTest, GetCurrentScene) {
        SceneManager::change_scene("Scene1");
        auto currentScene = SceneManager::get_current_scene();
        EXPECT_EQ(SceneManager::get_scene("Scene1"), currentScene);

        SceneManager::change_scene("Scene2");
        currentScene = SceneManager::get_current_scene();
        EXPECT_EQ(SceneManager::get_scene("Scene2"), currentScene);
    }
}  // namespace H2DE
