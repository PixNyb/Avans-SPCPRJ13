/**
 * @file graphics_facade.cpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the GraphicsFacade class implementation.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "graphics_facade.hpp"
#include "sdl_circle.hpp"
#include "sdl_rect.hpp"
#include "sdl_triangle.hpp"
#include <iostream>

GraphicsFacade::GraphicsFacade() {
    try {
        SdlInit = std::make_unique<SDLInit>();
    } catch (const std::exception& e) {
        std::cerr << "Exception during GraphicsFacade initialization: " << e.what() << std::endl;
    }
}

GraphicsFacade::~GraphicsFacade() {}

void GraphicsFacade::Init() {}

void GraphicsFacade::PollEvents(std::vector<Event>& events) {
    // implement features
}

void GraphicsFacade::CreateWindow(const std::string& title, int width, int height) {
    const char* c_title = title.c_str();
    if (!SdlWindow) {
        SdlWindow = std::make_unique<SDLWindow>(c_title, width, height);
    }
    SdlWindow->Create(c_title, width, height);
}

void GraphicsFacade::ClearScreen() {
    if (SdlWindow) {
        SdlWindow->ClearScreen();
    }
}

void GraphicsFacade::CreateRenderer() {
    if (SdlWindow) {
        SdlWindow->CreateRenderer();
    }
}

void GraphicsFacade::PresentScreen() {
    if (SdlWindow) {
        SdlWindow->PresentScreen();
    }
}

void GraphicsFacade::Delay(unsigned int ms) {
    if (SdlWindow) {
        SdlWindow->Delay(ms);
    }
}

void GraphicsFacade::DrawShape(Circle circle, SDL_Renderer* renderer) {
    const Vector2D& pos = circle.GetPosition();
    int x = static_cast<int>(pos.x);
    int y = static_cast<int>(pos.y);
    int rad = static_cast<int>(circle.GetRadius());

    SDLCircle sdlCircle(x, y, rad);
    sdlCircle.Draw(renderer);
}

void GraphicsFacade::DrawShape(Rectangle rectangle, SDL_Renderer* renderer){
    const Vector2D& pos = rectangle.GetPosition();

    SDLRect rect(static_cast<int>(pos.x), static_cast<int>(pos.y), rectangle.GetWidth(), rectangle.GetHeight());
    rect.Draw(renderer);
}

void GraphicsFacade::DrawShape(Triangle triangle, SDL_Renderer *renderer) {
    // Retrieve the vertices of the Triangle
    const Vector2D& v1 = triangle.GetVertex1();
    const Vector2D& v2 = triangle.GetVertex2();
    const Vector2D& v3 = triangle.GetVertex3();

    // Convert the vertices to the format expected by SDLTriangle
    auto x1 = static_cast<Sint16>(v1.x);
    auto y1 = static_cast<Sint16>(v1.y);
    auto x2 = static_cast<Sint16>(v2.x);
    auto y2 = static_cast<Sint16>(v2.y);
    auto x3 = static_cast<Sint16>(v3.x);
    auto y3 = static_cast<Sint16>(v3.y);

    // Create an SDLTriangle with the converted vertices
    SDLTriangle sdlTriangle(x1, y1, x2, y2, x3, y3);

    // Use SDLTriangle's Draw method to render the triangle
    sdlTriangle.Draw(renderer);
}