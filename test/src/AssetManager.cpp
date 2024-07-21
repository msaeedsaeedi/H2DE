#include "H2DE/AssetManager.hpp"

#include <gtest/gtest.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>

#include "H2DE/Exceptions/IOExceptions.hpp"

class AssetManagerTest : public ::testing::Test
{
    protected:
        std::string validUrl = "assets/texture.png";
        std::string invalidUrl = "assets/texture_invalid.png";
        std::string largeImageUrl = "assets/large_texture.png";
        std::string corruptedImageUrl = "assets/corrupted_texture.png";

        void SetUp() override {
            createfolder("assets");
            createValidTexture();
            createInvalidTexture();
            createLargeTexture();
            createCorruptedTexture();
        }

        void TearDown() override {
            remove(validUrl.c_str());
            remove(largeImageUrl.c_str());
            remove(corruptedImageUrl.c_str());
        }

        void createfolder(const std::string &folder) {
            std::string command = "mkdir -p " + folder;
            system(command.c_str());
        }

        void createValidTexture() {
            sf::Image image;
            image.create(100, 100, sf::Color::Red);
            image.saveToFile(validUrl);
        }

        void createInvalidTexture() {
            // No file creation for invalid texture
        }

        void createLargeTexture() {
            sf::Image image;
            image.create(2000, 2000, sf::Color::Green);
            image.saveToFile(largeImageUrl);
        }

        void createCorruptedTexture() {
            std::ofstream file(corruptedImageUrl);
            file << "This is not a valid image file.";
            file.close();
        }
};

TEST_F(AssetManagerTest, LoadTextureValid) {
    auto result = H2DE::AssetManager::load_texture(validUrl);

    EXPECT_EQ(std::get<0>(result), 0);
    EXPECT_GT(std::get<1>(result), 0.0f);
    EXPECT_GT(std::get<2>(result), 0.0f);
}

TEST_F(AssetManagerTest, LoadTextureInvalid) {
    EXPECT_THROW(H2DE::AssetManager::load_texture(invalidUrl),
                 H2DE::IOException);
}

TEST_F(AssetManagerTest, LoadTextureMultiple) {
    auto [index1, width1, height1] = H2DE::AssetManager::load_texture(validUrl);
    auto [index2, width2, height2] = H2DE::AssetManager::load_texture(validUrl);

    EXPECT_EQ(0, index1);
    EXPECT_EQ(1, index2);
    EXPECT_GT(width1, 0);
    EXPECT_GT(width2, 0);
    EXPECT_GT(height1, 0);
    EXPECT_GT(height2, 0);
    EXPECT_NE(index1, index2);
}

TEST_F(AssetManagerTest, LoadTextureDimensions) {
    sf::Image image;
    ASSERT_TRUE(image.loadFromFile(validUrl));
    float width = static_cast<float>(image.getSize().x);
    float height = static_cast<float>(image.getSize().y);

    auto [index, loadedWidth, loadedHeight] =
        H2DE::AssetManager::load_texture(validUrl);
    sf::Texture texture = H2DE::AssetManager::get_texture(index);
    EXPECT_EQ(width, static_cast<float>(texture.getSize().x));
    EXPECT_EQ(height, static_cast<float>(texture.getSize().y));
}

TEST_F(AssetManagerTest, LoadTextureEmptyPath) {
    std::string emptyUrl = "";

    EXPECT_THROW(H2DE::AssetManager::load_texture(emptyUrl), H2DE::IOException);
}

TEST_F(AssetManagerTest, LoadTextureNonImageFile) {
    std::string nonImageUrl = "assets/not_a_texture.txt";
    std::ofstream file(nonImageUrl);
    file << "This is a text file.";
    file.close();

    EXPECT_THROW(H2DE::AssetManager::load_texture(nonImageUrl),
                 H2DE::IOException);
    remove(nonImageUrl.c_str());
}

TEST_F(AssetManagerTest, LoadTextureLargeImage) {
    auto result = H2DE::AssetManager::load_texture(largeImageUrl);

    EXPECT_EQ(std::get<0>(result), 0);
    EXPECT_GT(std::get<1>(result), 0.0f);
    EXPECT_GT(std::get<2>(result), 0.0f);
}

TEST_F(AssetManagerTest, LoadTextureCorruptedImage) {
    EXPECT_THROW(H2DE::AssetManager::load_texture(corruptedImageUrl),
                 H2DE::IOException);
}

TEST_F(AssetManagerTest, LoadTextureConcurrent) {
    std::string url1 = validUrl;
    std::string url2 = validUrl;

    auto [index1, width1, height1] = H2DE::AssetManager::load_texture(url1);
    auto [index2, width2, height2] = H2DE::AssetManager::load_texture(url2);

    EXPECT_EQ(0, index1);
    EXPECT_EQ(1, index2);
    EXPECT_GT(width1, 0);
    EXPECT_GT(width2, 0);
    EXPECT_GT(height1, 0);
    EXPECT_GT(height2, 0);
    EXPECT_NE(index1, index2);
}

TEST_F(AssetManagerTest, LoadTextureSameUrlTwice) {
    auto [index1, width1, height1] = H2DE::AssetManager::load_texture(validUrl);
    auto [index2, width2, height2] = H2DE::AssetManager::load_texture(validUrl);

    EXPECT_EQ(0, index1);
    EXPECT_EQ(1, index2);
    EXPECT_GT(width1, 0);
    EXPECT_GT(width2, 0);
    EXPECT_GT(height1, 0);
    EXPECT_GT(height2, 0);
    EXPECT_NE(index1, index2);
}
