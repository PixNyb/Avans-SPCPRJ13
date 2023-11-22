/**
 * @file io_facade.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the IOFacade interface definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * IOFacade is an interface for input/output handling in the game engine. It
 * defines a standard set of operations for initializing the input system and
 * polling for events, which can be implemented by various concrete input
 * systems like SDL, GLFW, etc.
 *
 * Implementations of IOFacade are responsible for translating system-specific
 * input events into a generic format that can be used by the game engine.
 *
 * @see Event
 * @see SDL2InputHandler
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_IO_FACADE_HPP
#define DEFUNBOBENGINE_IO_FACADE_HPP

#include "circle.hpp"
#include "event.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "sdl_window.hpp"
#include "triangle.hpp"
#include "core_constants.hpp"
#include "texture.hpp"
#include <SDL.h>
#include <vector>

/**
 * @class IOFacade
 * @brief Interface for input/output handling in the game engine.
 *
 * This abstract class defines the necessary interface for input handling within
 * the engine. Concrete implementations are responsible for providing the logic
 * to initialize the input system and to poll for input events, returning them
 * in a consistent format.
 */
class IOFacade {
public:
    /**
     * @brief Virtual destructor for IOFacade.
     */
    virtual ~IOFacade() = default;

    /**
     * @brief Initializes the input handling system.
     *
     * Must be implemented by the concrete subclass to set up the specific input
     * system in use, such as SDL2 or GLFW.
     */
    virtual void Init() = 0;

    /**
     * @brief Polls for SDL input events.
     *
     * This function checks for new events from the SDL input system and returns them
     * as a vector of SDL_Event objects.
     * @return A vector containing all polled SDL_Event objects.
     */
    virtual std::vector<std::unique_ptr<Event>> PollEvents() = 0;

    /**
     * @brief Maps an SDL_Event to a custom Event.
     *
     * This method should be implemented by the concrete subclass to map an SDL_Event
     * to a custom Event object. It should take the SDL_Event as input and return a
     * unique pointer to a custom Event object.
     *
     * @param sdlEvent The SDL_Event to be mapped.
     * @return A unique pointer to a custom Event object.
     */
    virtual std::unique_ptr<Event> MapSdlEventToCustomEvent(const SDL_Event& sdlEvent) = 0;

    /**
    * @brief Creates a window with the specified properties.
    *
    * This method must be implemented by the concrete subclass to handle the creation
            * of a window. It should specify the window's title, width, and height, and delegate
    * the actual creation process to a window management system, such as SDL2, abstracted
            * by the sdl_window.hpp class. The method should manage the lifecycle of the window
            * and ensure it integrates properly with the input/output handling system of the engine.
    *
    * @param title The title to be displayed on the window's title bar.
    * @param width The width of the window in pixels.
    * @param height The height of the window in pixels.
    */
    virtual void CreateWindow(const std::string& title, int width, int height) = 0;

    /**
     * @brief delay execution for a specified number of milliseconds.
     * @param ms The number of milliseconds to delay execution.
     */
    virtual void Delay(unsigned int ms)  = 0;

    /**
     * @brief Clears the rendering target.
     *
     * This method should be implemented by derived classes to prepare the screen
     * for new rendering operations by clearing existing content. It ensures a clean
     * slate for each frame's rendering process.
     */
    virtual void ClearScreen() = 0;

    /**
     * @brief Creates the rendering context.
     *
     * Must be implemented by derived classes to initialize the renderer for the
     * graphics window. This method sets up the necessary context for rendering
     * graphics in the game engine.
     */
    virtual void CreateRenderer() = 0;

    /**
     * @brief Presents the rendered content on the screen.
     *
     * Implemented by derived classes, this method updates the window with the
     * currently rendered graphics, finalizing the frame. It's the last step in
     * the rendering pipeline for each frame.
     */
    virtual void PresentScreen() = 0;

    /**
     * @brief Draws a circle on the screen.
     *
     * This function should be implemented by the derived classes to handle the rendering
     * of a Circle object on the screen using the provided SDL_Renderer. It should take
     * the circle's properties such as position, radius, and color into account while rendering.
     *
     * @param circle A Circle object containing properties like position, radius, and color.
     * @param renderer A pointer to an SDL_Renderer to draw the circle.
     */
    virtual void DrawShape(Circle circle) = 0;

    /**
     * @brief Draws a line on the screen.
     * @param start The coordinates of the start point.
     * @param end The coordinates of the end point.
     */
    virtual void DrawLine(Line line) = 0;

    /**
     * @brief Draws a set of lines on the screen.
     * @param lines A vector of Line objects.
     */
    virtual void DrawLines(std::vector<Line> lines) = 0;

    /**
     * @brief Draws a rectangle on the screen.
     *
     * This function should be implemented by the derived classes to handle the rendering
     * of a Rectangle object on the screen using the provided SDL_Renderer. It should consider
     * the rectangle's properties such as position, dimensions, and color during the rendering process.
     *
     * @param rectangle A Rectangle object containing properties like position, dimensions, and color.
     * @param renderer A pointer to an SDL_Renderer to draw the rectangle.
     */
    virtual void DrawShape(Rectangle rectangle) = 0;

    /**
     * @brief Draws a Triangle shape on the rendering target.
     *
     * This virtual function is intended to be implemented in GraphicsFacade class to handle
     * the rendering of Triangle objects. The method should use the properties of the
     * Triangle (such as its vertices) to draw it on the provided SDL_Renderer.
     *
     * @param triangle A Triangle object containing the vertices and other properties of the shape.
     * @param renderer A pointer to an SDL_Renderer to draw the triangle.
     */
    virtual void DrawShape(Triangle triangle) = 0;


    /**
     * @brief Draws a Text object on the rendering target.
     *
     * This virtual function is intended to be implemented in GraphicsFacade class to handle
     * the rendering of Text objects. The method should use the properties of the
     * Text (such as its content, font size, and color) to draw it on the provided SDL_Renderer.
     *
     * @param text A Text object containing the content and other properties of the text.
     */
    virtual void DrawText(const Text& text) = 0;

    /**
     * @brief Draws a Texture object on the rendering target.
     *
     * This virtual function is intended to be implemented in GraphicsFacade class to handle
     * the rendering of Texture objects. The method should use the properties of the
     * Texture (such as its position and dimensions) to draw it on the provided SDL_Renderer.
     *
     * @param texture A Texture object containing the properties of the texture.
     */
    virtual void DrawSprite(const Texture& texture, Rectangle& rectangle) = 0;

    /**
     * @brief Renders an SDL_Texture on the rendering target.
     *
     * This virtual function is intended to be implemented in GraphicsFacade class to handle
     * the rendering of SDL_Texture objects. The method should use the properties of the
     * Texture (such as its position and dimensions) to draw it on the provided SDL_Renderer.
     *
     * @param sdlTexture An SDL_Texture object containing the properties of the texture.
     * @param rectangle The rectangle to render the texture in.
     */
    virtual void RenderSDLTexture(SDL_Texture* sdlTexture, Rectangle rectangle) = 0;

    /**
     * @brief Gets the cached SDL_Texture for a Texture object.
     * @param texture The Texture object to retrieve the cached SDL_Texture for.
     * @return The cached Texture.
     */
    virtual SDL_Texture* GetCachedSDLTexture(const Texture& texture) = 0;

    /**
     * @brief Creates an SDL_Texture from a Texture object.
     * @param texture The Texture object to create the SDL_Texture from.
     * @return The created SDL_Texture.
     */
    virtual SDL_Texture* CreateSDLTextureFromTexture(const Texture& texture) = 0;

    /**
     * @brief Caches an SDL_Texture for a Texture object.
     * @param texture The Texture object to cache the SDL_Texture for.
     * @param sdlTexture The SDL_Texture to cache.
     */
    virtual void CacheSDLTexture(const Texture& texture, SDL_Texture* sdlTexture) = 0;

    /**
     * @brief Gets the size of a sprite.
     * @param filePath The path to the sprite file.
     * @return The size of the sprite.
     */
    virtual Size GetSpriteSize(const std::string& filePath) = 0;
};

#endif //DEFUNBOBENGINE_IO_FACADE_HPP
