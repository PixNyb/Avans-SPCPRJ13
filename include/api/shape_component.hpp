/**
 * @file shape_component.hpp
 * @author "Melvin van Bree"
 * @brief A file containing the ShapeComponent class.
 * @version 0.1
 * @date 12/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_API_SHAPE_COMPONENT_HPP
#define DEFUNBOBENGINE_INCLUDE_API_SHAPE_COMPONENT_HPP

#include "component.hpp"
#include <geometry.hpp>

/**
 * @brief A class that represents a shape component.
 * @details A shape will not be translated by default. To translate a shape, add a
 * ShapeTranslationBehavior to the game object.
 */
class ShapeComponent : public Component
{
  private:
    std::vector<std::shared_ptr<Geometry>> _geometries;
    bool translate;

  public:
    explicit ShapeComponent(std::vector<std::shared_ptr<Geometry>> geometries,
                            bool translate = true);

    [[nodiscard]] std::vector<std::shared_ptr<Geometry>> GetGeometries() const;

    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;

    /**
     * @brief Specifies whether or not to translate the shapes relative to the game object
     * @return True if it should translate
     */
    [[nodiscard]] bool DoTranslate() const;
};

#endif // DEFUNBOBENGINE_INCLUDE_API_SHAPE_COMPONENT_HPP
