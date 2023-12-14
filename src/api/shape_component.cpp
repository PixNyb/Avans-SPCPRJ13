/**
 * @file shape_component.cpp
 * @author "Melvin van Bree"
 * @brief A file containing the ShapeComponent class.
 * @version 0.1
 * @date 12/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "shape_component.hpp"
#include <utility>

ShapeComponent::ShapeComponent(std::vector<std::shared_ptr<Geometry>> geometries, bool translate)
    : _geometries(std::move(geometries)), translate(translate)
{
}

std::vector<std::shared_ptr<Geometry>> ShapeComponent::GetGeometries() const { return _geometries; }

std::shared_ptr<Component> ShapeComponent::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<ShapeComponent>(_geometries);
}

bool ShapeComponent::DoTranslate() const { return translate; }
void ShapeComponent::AddGeometry(std::shared_ptr<Geometry> geo)
{
    _geometries.push_back(std::move(geo));
}
