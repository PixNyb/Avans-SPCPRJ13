/**
 * @file polygon.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Polygon class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * Polygon is a concrete implementation of the Geometry class that represents a
 * polygon in 2D space. It defines a polygon by a list of vertices and extends the
 * Geometry class by implementing the draw method to render a polygon on the screen.
 *
 * @see Geometry
 */

#ifndef DEFUNBOBENGINE_POLYGON_HPP
#define DEFUNBOBENGINE_POLYGON_HPP

#include "geometry.hpp"
#include "vector2d.hpp"
#include <cmath>
#include <vector>

/**
 * @class Polygon
 * @brief Represents a polygon and extends the Geometry class.
 *
 * This class is used to represent a polygon with a list of vertices (Vector2D objects).
 * The polygon is defined in world space, and its position and vertices are used to
 * render the shape to the screen. The draw method needs to be implemented to provide
 * rendering logic specific to the graphics library being used.
 */
class Polygon : public Geometry {
private:
    std::vector<Vector2D> vertices; ///< The vertices of the polygon.

public:
    /**
     * @brief Constructs a new Polygon object.
     *
     * @param pos The position of the polygon's reference point.
     * @param verts A list of vertices that define the polygon.
     */
    Polygon(const std::vector<Vector2D>& verts) : vertices(verts) {}

    int GetArea() override {
        int n = vertices.size();

        if (n < 3) {
            // A polygon with less than 3 vertices is not valid, and its area is zero.
            return 0;
        }

        int area = 0;

        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            area += (vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y);
        }

        // The shoelace formula involves adding the product of the last and first vertices, so we
        // add that product here.
        area += (vertices[n - 1].x * vertices[0].y - vertices[0].x * vertices[n - 1].y);

        return std::abs(area) / 2;
    }

    bool IsWithinArea(const Vector2D& start, const Vector2D& end) override {
        // TODO: Implement
        return true;
    }
};

#endif //DEFUNBOBENGINE_POLYGON_HPP
