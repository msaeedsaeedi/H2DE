#pragma once

#include <array>
#include <cmath>
#include <tuple>

namespace H2DE
{
    /**
     * @brief A 2D vector class.
     *
     * This class represents a 2D vector with x and y components.
     * It provides basic vector operations such as addition, subtraction, scalar multiplication, scalar division, dot
     * product, length, normalization, rotation, reflection, projection, and linear interpolation.
     * The class is designed to be used with float type.
     * The class is implicitly convertible to std::tuple<float, float> and std::array<float, 2>.
     */
    struct Vector2d {
            float x = 0, y = 0;

            /**
             * @brief Default constructor initializes the vector to (0, 0).
             */
            Vector2d() = default;

            /**
             * @brief Constructs a vector with specified x and y components.
             * @param x X component of the vector.
             * @param y Y component of the vector.
             */
            Vector2d(float x, float y);

            /**
             * @brief Implicitly converts the vector to a std::tuple<float, float>.
             * @return A tuple containing the x and y components of the vector.
             */
            operator std::tuple<float, float>() const;

            /**
             * @brief Implicitly converts the vector to a std::array<float, 2>.
             * @return An array containing the x and y components of the vector.
             */
            operator std::array<float, 2>() const;

            /**
             * @brief Adds two vectors.
             * @param other The vector to add.
             * @return A new vector that is the sum of this vector and the other vector.
             */
            Vector2d operator+(const Vector2d& other) const;

            /**
             * @brief Subtracts another vector from this vector.
             * @param other The vector to subtract.
             * @return A new vector that is the difference between this vector and the other vector.
             */
            Vector2d operator-(const Vector2d& other) const;

            /**
             * @brief Multiplies the vector by a scalar.
             * @param scalar The scalar value to multiply by.
             * @return A new vector that is the product of this vector and the scalar.
             */
            Vector2d operator*(float scalar) const;

            /**
             * @brief Multiplies a scalar by the vector.
             * @param scalar The scalar value to multiply by.
             * @param vector The vector to multiply.
             * @return A new vector that is the product of the scalar and the vector.
             */
            friend Vector2d operator*(float scalar, const Vector2d& vector);

            /**
             * @brief Divides the vector by a scalar.
             * @param scalar The scalar value to divide by.
             * @return A new vector that is the quotient of this vector and the scalar.
             * @throws std::invalid_argument if the scalar is zero.
             */
            Vector2d operator/(float scalar) const;

            /**
             * @brief Adds another vector to this vector in place.
             * @param other The vector to add.
             * @return A reference to this vector after addition.
             */
            Vector2d& operator+=(const Vector2d& other);

            /**
             * @brief Subtracts another vector from this vector in place.
             * @param other The vector to subtract.
             * @return A reference to this vector after subtraction.
             */
            Vector2d& operator-=(const Vector2d& other);

            /**
             * @brief Multiplies this vector by a scalar in place.
             * @param scalar The scalar value to multiply by.
             * @return A reference to this vector after multiplication.
             */
            Vector2d& operator*=(float scalar);

            /**
             * @brief Divides this vector by a scalar in place.
             * @param scalar The scalar value to divide by.
             * @return A reference to this vector after division.
             * @throws std::invalid_argument if the scalar is zero.
             */
            Vector2d& operator/=(float scalar);

            /**
             * @brief Compares this vector with another for equality.
             * @param other The vector to compare with.
             * @return True if the vectors are equal, false otherwise.
             */
            bool operator==(const Vector2d& other) const;

            /**
             * @brief Compares this vector with another for inequality.
             * @param other The vector to compare with.
             * @return True if the vectors are not equal, false otherwise.
             */
            bool operator!=(const Vector2d& other) const;

            /**
             * @brief Calculates the dot product of this vector and another vector.
             * @param other The vector to dot with.
             * @return The dot product as a float.
             */
            float dot(const Vector2d& other) const;

            /**
             * @brief Computes the length (magnitude) of the vector.
             * @return The length of the vector.
             */
            float length() const;

            /**
             * @brief Normalizes the vector in place to have a length of 1.
             * @return A reference to this normalized vector.
             */
            Vector2d& normalize();

            /**
             * @brief Returns a normalized version of the vector.
             * @return A new vector that is the normalized version of this vector.
             */
            Vector2d normalized() const;

            /**
             * @brief Rotates the vector by a specified angle (in radians) in place.
             * @param angle The angle to rotate by, in radians.
             * @return A reference to this rotated vector.
             */
            Vector2d& rotate(float angle);

            /**
             * @brief Returns a rotated version of the vector by a specified angle (in radians).
             * @param angle The angle to rotate by, in radians.
             * @return A new vector that is the rotated version of this vector.
             */
            Vector2d rotated(float angle) const;

            /**
             * @brief Reflects the vector across a given normal in place.
             * @param normal The normal vector to reflect across.
             * @return A reference to this reflected vector.
             */
            Vector2d& reflect(const Vector2d& normal);

            /**
             * @brief Returns a reflected version of the vector across a given normal.
             * @param normal The normal vector to reflect across.
             * @return A new vector that is the reflected version of this vector.
             */
            Vector2d reflected(const Vector2d& normal) const;

            /**
             * @brief Projects this vector onto another vector in place.
             * @param other The vector to project onto.
             * @return A reference to this projected vector.
             */
            Vector2d& project(const Vector2d& other);

            /**
             * @brief Returns a projected version of this vector onto another vector.
             * @param other The vector to project onto.
             * @return A new vector that is the projected version of this vector.
             */
            Vector2d projected(const Vector2d& other) const;

            /**
             * @brief Performs linear interpolation between this vector and another vector in place.
             * @param other The target vector for interpolation.
             * @param t Interpolation factor (0 <= t <= 1).
             * @return A reference to this interpolated vector.
             */
            Vector2d& lerp(const Vector2d& other, float t);

            /**
             * @brief Returns a linearly interpolated version of this vector between another vector.
             * @param other The target vector for interpolation.
             * @param t Interpolation factor (0 <= t <= 1).
             * @return A new vector that is the interpolated version of this vector.
             */
            Vector2d lerped(const Vector2d& other, float t) const;
    };
};  // namespace H2DE