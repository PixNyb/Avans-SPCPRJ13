//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_GEOMETRY_HPP
#define DEFUNBOBENGINE_GEOMETRY_HPP

#include "vector.hpp"

class Geometry {
protected:
    Vector2D position;

public:
    Geometry(const Vector2D& pos) : position(pos) {}
    virtual ~Geometry() {}
    virtual void draw() const = 0;
};

#endif //DEFUNBOBENGINE_GEOMETRY_HPP
