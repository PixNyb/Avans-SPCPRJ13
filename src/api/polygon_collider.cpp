//
// Created by Eigenaar on 16-11-2023.
//

#include "polygon_collider.hpp"

void PolygonCollider::Vertices(const std::vector<Point> &vertices) {
    this->vertices = vertices;
}

std::shared_ptr<Component> PolygonCollider::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<PolygonCollider>(*this);
}

PolygonCollider::PolygonCollider(const PolygonCollider &other) : Collider(other) {
    vertices = other.vertices;
}
