//
// Created by Eigenaar on 16-11-2023.
//

#ifndef DEFUNBOBENGINE_POLYGON_COLLIDER_HPP
#define DEFUNBOBENGINE_POLYGON_COLLIDER_HPP


#include "point.hpp"
#include "vector"
#include "collider.hpp"

class PolygonCollider : public Collider {
public:
    PolygonCollider() = default;

    void Vertices(const std::vector<Point>& vertices);

    std::vector<Point> Vertices() const {return vertices;}
private:
    std::vector<Point> vertices;
};


#endif //DEFUNBOBENGINE_POLYGON_COLLIDER_HPP
