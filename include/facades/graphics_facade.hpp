/**
 * @file graphics_facade.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief Defines the GraphicsFacade class for managing graphics operations in the DefunBobEngine.
 * @version 0.1
 * @date 2023-11-12
 *
 * The GraphicsFacade class extends IOFacade, specifically focusing on the graphics subsystem.
 * It handles the initialization, management, and rendering of graphics using SDL. This includes
 * managing the graphics window and rendering context, processing graphics-related events,
 * and providing a high-level interface for rendering operations.
 *
 * @see IOFacade
 * @see SDLWindow
 * @copyright Copyright (c) 2023 Robin Pijnappels
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
    std::unique_ptr<SDLInit> SdlInit; /**< Unique pointer to SDLInit for SDL initialization. */
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
     * Sets up the necessary components for graphics operations, including SDL initialization.
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

    /**
     * @brief Sets up the graphics window.
     *
     * Configures the window properties but does not create it immediately.
     * @param title Window title.
     * @param width Window width.
     * @param height Window height.
     */
    void SetupWindow(const char* title, int width, int height) {
        SdlWindow = std::make_unique<SDLWindow>(title, width, height);
    }

    /**
     * @brief Creates the graphics window.
     *
     * Initializes and displays the window based on previously set properties.
     * @param title Window title.
     * @param width Window width.
     * @param height Window height.
     */
    void CreateWindow(const char* title, int width, int height) override {
        if (SdlWindow) {
            SdlWindow->Create(title, width, height);
        }
    }

    /**
     * @brief Clears the rendering target.
     *
     * Prepares the screen for new rendering operations by clearing existing content.
     */
    void ClearScreen() {
        if (SdlWindow){
            SdlWindow->ClearScreen();
        }
    }

    /**
     * @brief Creates the rendering context.
     *
     * Initializes the renderer for the graphics window.
     */
    void CreateRenderer()
    {
        if (SdlWindow){
            SdlWindow->CreateRenderer();
        }
    }

    /**
    * @brief Presents the rendered content on the screen.
    *
    * Updates the window with rendered graphics, finalizing the current frame.
    */
    void PresentScreen()
    {
        if (SdlWindow){
            SdlWindow->PresentScreen();
        }
    }

    /**
     * @brief Delays execution for a specified duration.
     *
     * Introduces a pause in processing, useful for controlling frame rates.
     * @param ms Delay duration in milliseconds.
     */
    void Delay(unsigned int ms) override {
        SdlWindow->Delay(ms);
    }





};


#endif //DEFUNBOBENGINE_GRAPHICS_FACADE_HPP
