/// @file

#ifndef DEFUNBOBENGINE_POINT_H
#define DEFUNBOBENGINE_POINT_H

/**
 * @brief Struct representing both a 2D point and a 2D vector.
 */
struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}

    Point operator+(const Point &other) const {
            return {x + other.x, y + other.y};
    }

    Point operator-(const Point &other) const {
            return {x - other.x, y - other.y};
    }
};

#endif // DEFUNBOBENGINE_POINT_H
