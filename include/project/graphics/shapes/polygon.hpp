//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_POLYGON_HPP
#define DEFUNBOBENGINE_POLYGON_HPP

#include "geometry.hpp"
#include <vector>

class Polygon : public Geometry {
private:
    std::vector<Vector2D> vertices;

public:
    Polygon(const Vector2D& pos, const std::vector<Vector2D>& verts)
            : Geometry(pos), vertices(verts) {}


    void draw() const override {}
};

#endif //DEFUNBOBENGINE_POLYGON_HPP
