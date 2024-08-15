#include "H2DE/Graphics/Vector2d.hpp"

#include <gtest/gtest.h>

class Vector2dTest : public ::testing::Test
{
    protected:
        H2DE::Vector2d* vector;

        void SetUp() override {
            vector = new H2DE::Vector2d(1.0f, 2.0f);
        }

        void TearDown() override {
            delete vector;
        }
};

TEST_F(Vector2dTest, Init) {
    EXPECT_FLOAT_EQ(vector->x, 1.0f);
    EXPECT_FLOAT_EQ(vector->y, 2.0f);
}

TEST_F(Vector2dTest, Conversion) {
    auto tuple = static_cast<std::tuple<float, float>>(*vector);
    EXPECT_FLOAT_EQ(std::get<0>(tuple), 1.0f);
    EXPECT_FLOAT_EQ(std::get<1>(tuple), 2.0f);

    auto array = static_cast<std::array<float, 2>>(*vector);
    EXPECT_FLOAT_EQ(array[0], 1.0f);
    EXPECT_FLOAT_EQ(array[1], 2.0f);
}

TEST_F(Vector2dTest, Addition) {
    H2DE::Vector2d other(3.0f, 4.0f);
    auto result = *vector + other;
    EXPECT_FLOAT_EQ(result.x, 4.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

TEST_F(Vector2dTest, Subtraction) {
    H2DE::Vector2d other(3.0f, 4.0f);
    auto result = *vector - other;
    EXPECT_FLOAT_EQ(result.x, -2.0f);
    EXPECT_FLOAT_EQ(result.y, -2.0f);
}

TEST_F(Vector2dTest, Multiplication) {
    auto result = *vector * 2.0f;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST_F(Vector2dTest, Division) {
    auto result = *vector / 2.0f;
    EXPECT_FLOAT_EQ(result.x, 0.5f);
    EXPECT_FLOAT_EQ(result.y, 1.0f);
}

TEST_F(Vector2dTest, ScalarMultiplication) {
    auto result = 2.0f * *vector;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST_F(Vector2dTest, Equality) {
    H2DE::Vector2d other(1.0f, 2.0f);
    EXPECT_EQ(*vector, other);
}

TEST_F(Vector2dTest, Inequality) {
    H2DE::Vector2d other(3.0f, 4.0f);
    EXPECT_NE(*vector, other);
}

TEST_F(Vector2dTest, AdditionAssignment) {
    H2DE::Vector2d other(3.0f, 4.0f);
    *vector += other;
    EXPECT_FLOAT_EQ(vector->x, 4.0f);
    EXPECT_FLOAT_EQ(vector->y, 6.0f);
}

TEST_F(Vector2dTest, SubtractionAssignment) {
    H2DE::Vector2d other(3.0f, 4.0f);
    *vector -= other;
    EXPECT_FLOAT_EQ(vector->x, -2.0f);
    EXPECT_FLOAT_EQ(vector->y, -2.0f);
}

TEST_F(Vector2dTest, MultiplicationAssignment) {
    *vector *= 2.0f;
    EXPECT_FLOAT_EQ(vector->x, 2.0f);
    EXPECT_FLOAT_EQ(vector->y, 4.0f);
}

TEST_F(Vector2dTest, DivisionAssignment) {
    *vector /= 2.0f;
    EXPECT_FLOAT_EQ(vector->x, 0.5f);
    EXPECT_FLOAT_EQ(vector->y, 1.0f);
}

TEST_F(Vector2dTest, EqualityAssignment) {
    H2DE::Vector2d other(1.0f, 2.0f);
    *vector = other;
    EXPECT_EQ(*vector, other);
}

TEST_F(Vector2dTest, DotProduct) {
    H2DE::Vector2d other(3.0f, 4.0f);
    auto result = vector->dot(other);
    EXPECT_FLOAT_EQ(result, 11.0f);
}

TEST_F(Vector2dTest, Length) {
    auto result = vector->length();
    EXPECT_FLOAT_EQ(result, 2.23606797749979f);
}

TEST_F(Vector2dTest, Normalize) {
    vector->normalize();
    EXPECT_FLOAT_EQ(vector->x, 0.44721359014511108f);
    EXPECT_FLOAT_EQ(vector->y, 0.89442718029022217f);
}

TEST_F(Vector2dTest, Rotate) {
    vector->rotate(90.0f * M_PI / 180.0f);
    EXPECT_FLOAT_EQ(vector->x, -2.0f);
    EXPECT_FLOAT_EQ(vector->y, 1.0f);
}

TEST_F(Vector2dTest, Reflect) {
    H2DE::Vector2d normal(1.0f, 0.0f);
    vector->reflect(normal);
    EXPECT_FLOAT_EQ(vector->x, -1.0f);
    EXPECT_FLOAT_EQ(vector->y, 2.0f);
}

TEST_F(Vector2dTest, Project) {
    H2DE::Vector2d vector(6.0f, 8.0f);
    H2DE::Vector2d other(3.0f, 4.0f);
    vector.project(other);
    EXPECT_FLOAT_EQ(vector.x, 6.0f);
    EXPECT_FLOAT_EQ(vector.y, 8.0f);
}

TEST_F(Vector2dTest, Lerp) {
    H2DE::Vector2d other(3.0f, 4.0f);
    vector->lerp(other, 0.5f);
    EXPECT_FLOAT_EQ(vector->x, 2.0f);
    EXPECT_FLOAT_EQ(vector->y, 3.0f);
}