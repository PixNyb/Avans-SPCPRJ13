#include "graphics_facade.hpp"
#include "sdl_circle.hpp"
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
    sdlCircle.draw(renderer);
}