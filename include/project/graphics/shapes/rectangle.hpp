//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_RECTANGLE_HPP
#define DEFUNBOBENGINE_RECTANGLE_HPP

#include "geometry.hpp"

class Rectangle : public Geometry {

private:
    float height;
    float width;

public:
    Rectangle(const Vector2D& pos, float h, float w)
            : Geometry(pos), height(h), width(w) {}

    void draw() const override {}
};

#endif //DEFUNBOBENGINE_RECTANGLE_HPP
