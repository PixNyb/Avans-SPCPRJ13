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
    Polygon(const Vector2D& pos, const std::vector<Vector2D>& verts)
            : Geometry(pos), vertices(verts) {}

    /**
     * @brief Draws the polygon using the rendering system.
     *
     * Implementations should use the position and vertices to draw the polygon
     * to the screen. The actual rendering implementation would depend on the
     * graphics library being used, and might involve drawing lines between each
     * pair of vertices or using a more complex polygon filling algorithm.
     */
    void Draw() const override {
        // Rendering logic goes here
    }
};

#endif //DEFUNBOBENGINE_POLYGON_HPP
