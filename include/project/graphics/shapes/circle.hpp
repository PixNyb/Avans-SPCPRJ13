//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_CIRCLE_HPP
#define DEFUNBOBENGINE_CIRCLE_HPP

#include "geometry.hpp"

class Circle : public Geometry {
private:
    float radius;

public:
    Circle(const Vector2D& pos, float r)
            : Geometry(pos), radius(r) {}


    void draw() const override {}
};

#endif //DEFUNBOBENGINE_CIRCLE_HPP
