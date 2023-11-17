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
#include "line.hpp"
#include "sdl_init.hpp"
#include "sdl_render.hpp"
#include <SDL.h>
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

    void ResetColor();
    void SetColor(Color color);
public:

    /**
     * @brief Constructs a new GraphicsFacade object.
     *
     * This constructor initializes the GraphicsFacade object, setting up the necessary
     * components for managing graphics operations in the DefunBobEngine. It prepares the
     * class for subsequent initialization of the SDL graphics subsystem and window management.
     * The actual initialization of SDL and window creation is deferred until the Init and
     * CreateWindow methods are called.
     */
    GraphicsFacade();

    /**
     * @brief Destroys the GraphicsFacade object.
     *
     * This destructor ensures the proper deallocation and cleanup of resources used by
     * the GraphicsFacade. It handles the release of the SDL-related resources and other
     * graphics components managed by this class. Ensuring that all resources are correctly
     * released is critical for preventing memory leaks and other resource management issues.
     */
    ~GraphicsFacade() override;

    /**
     * @brief Initializes the graphics system.
     *
     * Sets up the necessary components for graphics operations, including SDL initialization.
     */
    void Init() override;

    /**
    * @brief Polls and processes graphics-related events.
    *
    * @param events A vector of Event objects to be filled with polled events.
    */
    void PollEvents(std::vector<Event>& events) override;

    /**
     * @brief Creates the graphics window.
     *
     * Initializes and displays the window based on previously set properties.
     * @param title Window title.
     * @param width Window width.
     * @param height Window height.
     */
    void CreateWindow(const std::string& title, int width, int height) override;


    /**
     * @brief Clears the rendering target.
     *
     * Prepares the screen for new rendering operations by clearing existing content.
     */
    void ClearScreen() override;

    /**
     * @brief Creates the rendering context.
     *
     * Initializes the renderer for the graphics window.
     */
    void CreateRenderer() override;

    /**
    * @brief Presents the rendered content on the screen.
    *
    * Updates the window with rendered graphics, finalizing the current frame.
    */
    void PresentScreen() override;

    /**
     * @brief Delays execution for a specified duration.
     *
     * Introduces a pause in processing, useful for controlling frame rates.
     * @param ms Delay duration in milliseconds.
     */
    void Delay(unsigned int ms) override;

    /**
     * @brief Draws a circle on the screen.
     *
     * @param circle A Circle object containing properties like position, radius, and color.
     * @param renderer A pointer to an SDL_Renderer to draw the circle.
     */
    void DrawShape(Circle circle) override;

    /**
     * @brief Draws a rectangle on the screen.
     *
     * @param rectangle A Rectangle object containing properties like position, dimensions, and color.
     * @param renderer A pointer to an SDL_Renderer to draw the rectangle.
     */
    void DrawShape(Rectangle rectangle) override;

    /**
     * @brief Draws a Triangle shape on the rendering target.
     *
     *
     * @param triangle A Triangle object containing the vertices and other properties of the shape.
     * @param renderer A pointer to an SDL_Renderer to draw the triangle.
     */
    void DrawShape(Triangle triangle) override;


    void DrawLine(Line line) override;

    void DrawLines(std::vector<Line> lines) override;

    void DrawText(const Text& text) override;
};


#endif //DEFUNBOBENGINE_GRAPHICS_FACADE_HPP
