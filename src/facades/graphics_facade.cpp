#include "graphics_facade.hpp"
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

void GraphicsFacade::CreateWindow(const char* title, int width, int height) {
    if (!SdlWindow) {
        SdlWindow = std::make_unique<SDLWindow>(title, width, height);
    }
    SdlWindow->Create(title, width, height);
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