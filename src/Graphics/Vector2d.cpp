#include "H2DE/Graphics/Vector2d.hpp"

namespace H2DE
{
    Vector2d::Vector2d(float x, float y) : x(x), y(y) {
    }

    Vector2d::operator std::tuple<float, float>() const {
        return {x, y};
    }

    Vector2d::operator std::array<float, 2>() const {
        return {x, y};
    }

    Vector2d Vector2d::operator+(const Vector2d& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2d Vector2d::operator-(const Vector2d& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2d Vector2d::operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    Vector2d operator*(float scalar, const Vector2d& vector) {
        return vector * scalar;
    }

    Vector2d Vector2d::operator/(float scalar) const {
        return {x / scalar, y / scalar};
    }

    Vector2d& Vector2d::operator+=(const Vector2d& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2d& Vector2d::operator-=(const Vector2d& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2d& Vector2d::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2d& Vector2d::operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool Vector2d::operator==(const Vector2d& other) const {
        return x == other.x && y == other.y;
    }

    bool Vector2d::operator!=(const Vector2d& other) const {
        return !(*this == other);
    }

    float Vector2d::dot(const Vector2d& other) const {
        return x * other.x + y * other.y;
    }

    float Vector2d::length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2d& Vector2d::normalize() {
        return *this /= length();
    }

    Vector2d Vector2d::normalized() const {
        return Vector2d(*this).normalize();
    }

    Vector2d& Vector2d::rotate(float angle) {
        float s = std::sin(angle);
        float c = std::cos(angle);
        return *this = {x * c - y * s, x * s + y * c};
    }

    Vector2d Vector2d::rotated(float angle) const {
        return Vector2d(*this).rotate(angle);
    }

    Vector2d& Vector2d::reflect(const Vector2d& normal) {
        return *this -= normal * 2 * dot(normal);
    }

    Vector2d Vector2d::reflected(const Vector2d& normal) const {
        return Vector2d(*this).reflect(normal);
    }

    Vector2d& Vector2d::project(const Vector2d& other) {
        float scalar = dot(other) / other.dot(other);
        return *this = other * scalar;
    }

    Vector2d Vector2d::projected(const Vector2d& other) const {
        return Vector2d(*this).project(other);
    }

    Vector2d& Vector2d::lerp(const Vector2d& other, float t) {
        return *this += (other - *this) * t;
    }

    Vector2d Vector2d::lerped(const Vector2d& other, float t) const {
        return Vector2d(*this).lerp(other, t);
    }
};  // namespace H2DE