/**
 * @file debug.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines a set of debugging utilities in the DefunBobEngine.
 * This file includes functions for drawing debug lines, logging messages, errors, and warnings.
 * These utilities are useful for development and debugging processes, providing visual and console-based
 * feedback to assist in the game development process.
 *
 * @copyright Copyright (c) 2023
 */


#ifndef DEFUNBOBENGINE_DEBUG_HPP
#define DEFUNBOBENGINE_DEBUG_HPP

#include <string>
#include "color.hpp"
#include "point.hpp"

/**
 * @namespace Debug
 * @brief Provides convenient debugging functions.
 *
 * The Debug namespace contains functions for drawing in the game world and logging messages,
 * which are essential tools for game developers to debug and visualize various aspects of their game.
 */
namespace Debug {

    /**
     * @brief Draws a colored line between specified start and end points.
     * @param start The starting point.
     * @param end The end point.
     * @param color The line color, defaults to white.
     */
    void DrawLine(const Point& start, const Point& end, const Color& color = Color::white());

    /**
     * @brief Logs a message to the Console.
     * @param message The message to write.
     */
    void Log(const std::string& message);

    /**
     * @brief A variant of Debug.Log that logs an error message to the console.
     * @param message The message to write.
     */
    void LogError(const std::string& error);

    /**
     * @brief A variant of Debug.Log that logs a warning message to the console.
     * @param message The message to write.
     */
    void LogWarning(const std::string& warning);

}

#endif //DEFUNBOBENGINE_DEBUG_HPP
