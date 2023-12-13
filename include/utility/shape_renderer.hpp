/**
 * @file shape_renderer.hpp
 * @author "Melvin van Bree"
 * @brief A file containing the ShapeRenderer class.
 * @version 0.1
 * @date 12/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_SRC_UTILITY_SHAPE_RENDERER_HPP
#define DEFUNBOBENGINE_SRC_UTILITY_SHAPE_RENDERER_HPP

#include "circle.hpp"
#include "geometry_visitor.hpp"
#include "line.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <io_facade.hpp>
#include <memory>

/**
 * @brief A visitor class that can render shapes.
 */
class ShapeRenderer : public GeometryVisitor
{
  private:
    std::shared_ptr<IOFacade> _ioFacade; ///< The io facade.

  public:
    /**
     * @brief Construct a new Shape Renderer object.
     * @param ioFacade The io facade.
     */
    explicit ShapeRenderer(std::shared_ptr<IOFacade> ioFacade);

    void Visit(Circle &circle) override;
    void Visit(Line &line) override;
    void Visit(Rectangle &rectangle) override;
    void Visit(Polygon &polygon) override;
    void Visit(Triangle &triangle) override;
};

#endif // DEFUNBOBENGINE_SRC_UTILITY_SHAPE_RENDERER_HPP
