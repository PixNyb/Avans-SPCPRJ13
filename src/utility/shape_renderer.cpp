/**
 * @file shape_renderer.cpp
 * @author "Melvin van Bree"
 * @brief A file containing the ShapeRenderer class.
 * @version 0.1
 * @date 12/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "shape_renderer.hpp"
ShapeRenderer::ShapeRenderer(std::shared_ptr<IOFacade> ioFacade) : _ioFacade(std::move(ioFacade)) {}
void ShapeRenderer::Visit(Circle &circle) { _ioFacade->DrawShape(circle); }
void ShapeRenderer::Visit(Line &line) { _ioFacade->DrawLine(line); }
void ShapeRenderer::Visit(Rectangle &rectangle) { _ioFacade->DrawShape(rectangle); }
void ShapeRenderer::Visit(Polygon &polygon)
{
    // TODO: Implement
}
void ShapeRenderer::Visit(Triangle &triangle) { _ioFacade->DrawShape(triangle); }
