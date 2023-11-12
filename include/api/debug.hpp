/// @file

#ifndef DEFUNBOBENGINE_DEBUG_HPP
#define DEFUNBOBENGINE_DEBUG_HPP

#include "color.hpp"
#include "point.hpp"
#include <string>

/**
 * @brief Some convenient debugging functions.
 */
namespace Debug
{

/**
 * @brief Draws a colored line between specified start and end points.
 * @param start The starting point.
 * @param end The end point.
 * @param color The line color, defaults to white.
 */
void DrawLine(const Point &start, const Point &end, const Color &color = Color::white());

/**
 * @brief Logs a message to the Console.
 * @param message The message to write.
 */
void Log(const std::string &message);

/**
 * @brief A variant of Debug.Log that logs an error message to the console.
 * @param message The message to write.
 */
void LogError(const std::string &error);

/**
 * @brief A variant of Debug.Log that logs a warning message to the console.
 * @param message The message to write.
 */
void LogWarning(const std::string &warning);

} // namespace Debug

#endif // DEFUNBOBENGINE_DEBUG_HPP
