/**
 * @file graphics_facade.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief Defines the GraphicsFacade class, responsible for managing graphics-related operations.
 * @version 0.1
 * @date 2023-11-12
 *
 * The GraphicsFacade class extends the IOFacade and provides functionalities specific to the
 * graphics subsystem of the application. It encapsulates the handling of a graphics window
 * and related operations, abstracting the complexities involved in graphics management.
 *
 * @see IOFacade
 * @see SDLWindow
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_GRAPHICS_FACADE_HPP
#define DEFUNBOBENGINE_GRAPHICS_FACADE_HPP

#include "io_facade.hpp"
#include "sdl_render.hpp"
#include "sdl_init.hpp"
#include <memory>

/**
 * @class GraphicsFacade
 * @brief Manages graphics operations and interfaces with SDL for window management.
 *
 * This class is responsible for initializing and managing the graphics window, handling
 * graphics-related events, and providing a high-level interface for graphics operations.
 */
class GraphicsFacade : public IOFacade {
private:
    std::unique_ptr<SDLWindow> SdlWindow; /**< Unique pointer to SDLWindow for managing the graphics window. */
    std::unique_ptr<SDLInit> SdlInit;
public:
    /**
     * @brief Default constructor for GraphicsFacade.
     *
     * Initializes the GraphicsFacade object with default values.
     */
    GraphicsFacade() = default;
    /**
     * @brief Virtual destructor for GraphicsFacade.
     *
     * Ensures proper cleanup of resources when the GraphicsFacade object is destroyed.
     */
    virtual ~GraphicsFacade() {}

    /**
     * @brief Initializes the graphics system.
     *
     * This function should be called to set up the necessary graphics components before
     * any graphics operations are performed.
     */
    void Init() override {
        SdlInit = std::make_unique<SDLInit>();
    }

    /**
    * @brief Polls and processes graphics-related events.
    *
    * @param events A vector of Event objects to be filled with polled events.
    */
    void PollEvents(std::vector<Event>& events) override;

    void SetupWindow(const char* title, int width, int height) {
        SdlWindow = std::make_unique<SDLWindow>(title, width, height);
    }

    void CreateWindow(const char* title, int width, int height) override {
        if (SdlWindow) {
            SdlWindow->Create(title, width, height);
        }
    }

    void ClearScreen() {
        if (SdlWindow){
            SdlWindow->ClearScreen();
        }
    }

    void CreateRenderer()
    {
        if (SdlWindow){
            SdlWindow->CreateRenderer();
        }
    }

    void PresentScreen()
    {
        if (SdlWindow){
            SdlWindow->PresentScreen();
        }
    }

    void Delay(unsigned int ms) override {
        SdlWindow->Delay(ms);
    }





};


#endif //DEFUNBOBENGINE_GRAPHICS_FACADE_HPP
