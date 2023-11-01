#include <math.h>

#pragma once

struct Position2D {
    float x{ 0.f };
    float y{ 0.f };

    constexpr Position2D operator+(const Position2D& other)const
    {
        Position2D v{};
        v.x = x + other.x;
        v.y = y + other.y;
        return v;
    }
    constexpr Position2D operator-(const Position2D& other)const
    {
        Position2D v{};
        v.x = x - other.x;
        v.y = y - other.y;
        return v;
    }
    Position2D &operator+=(const Position2D& other)
    {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }
    Position2D &operator-=(const Position2D& other)
    {
        x = x - other.x;
        y = y - other.y;
        return *this;
    }

    float length() const {
        return sqrt(x*x + y * y);
    }

    Position2D normalized() {
        float l = length();

        return Position2D{ x / l, y / l };
    }
    constexpr Position2D operator*(float other)const
    {
        Position2D v{};
        v.x = x * other;
        v.y = y * other;
        return v;
    }
};