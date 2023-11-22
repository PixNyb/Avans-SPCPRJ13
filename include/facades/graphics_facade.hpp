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
#include <map>

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

    std::map<std::string, SDL_Texture*> textureCache; /**< Map of texture file paths to SDL_Texture pointers. */

    /**
     * @brief resets the color to the default color specified in the Constants.
     */
    void ResetColor();

    /**
     * @brief Sets the color for rendering operations.
     *
     * This method sets the color for subsequent rendering operations. It is used internally
     * by the DrawShape methods to set the color of the shape to be drawn.
     * @param color The color to be set.
     */
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
    */
    std::vector<std::unique_ptr<Event>> PollEvents() override;

    /**
     * @brief Maps an SDL_Event to a custom Event.
     *
     * This method maps an SDL_Event to a custom Event, which is used to abstract the
     * SDL event system from the rest of the engine. It is used internally by the PollEvents
     * method to process SDL events and return them as custom events.
     * @param sdlEvent The SDL_Event to be mapped.
     * @return A unique pointer to the mapped Event.
     */
    std::unique_ptr<Event> MapSdlEventToCustomEvent(const SDL_Event& sdlEvent) override;

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

    /**
     * @brief Creates a texture from an image file.
     *
     * This method creates a texture from an image file, which can then be used for rendering.
     * @param texture The texture to be created.
     */
    void DrawSprite(const Texture& texture, Rectangle& rectangle) override;

    /**
     * @brief Creates an SDL_Texture from an image file.
     *
     * This method creates an SDL_Texture from an image file, which can then be used for rendering.
     * @param sdlTexture The SDL_Texture to be created.
     * @param rectangle The rectangle to render the texture in.
     */
    void RenderSDLTexture(SDL_Texture* sdlTexture, Rectangle rectangle) override;

    /**
     * @brief Gets the cached texture if it exists.
     * @param texture The texture to get the cached SDL_Texture for.
     */
    SDL_Texture* GetCachedSDLTexture(const Texture& texture) override;

    /**
     * @brief Creates an SDL_Texture from a Texture object.
     * @param texture The Texture object to create the SDL_Texture from.
     * @return The created SDL_Texture.
     */
    SDL_Texture* CreateSDLTextureFromTexture(const Texture& texture) override;

    /**
     * @brief Caches an SDL_Texture for a Texture object.
     * @param texture The Texture object to cache the SDL_Texture for.
     * @param sdlTexture The SDL_Texture to cache.
     */
    void CacheSDLTexture(const Texture& texture, SDL_Texture* sdlTexture) override;
};


#endif //DEFUNBOBENGINE_GRAPHICS_FACADE_HPP
