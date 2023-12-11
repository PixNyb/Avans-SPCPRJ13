/**
 * @file CoreConstants.hpp
 * @author melvin van bree
 * @brief Meant to provide a way to store constants that are used in the core of the engine.
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_CORECONSTANTS_HPP
#define DEFUNBOBENGINE_CORECONSTANTS_HPP

#include "color.hpp"
#include "text.hpp"
#include <string>

namespace CoreConstants
{
namespace Text
{
const int DEFAULT_SIZE = 12;
// TODO: Implement better way to handle this
const std::string DEFAULT_FONT_PATH = "../resources/fonts/OpenSans-Normal.ttf";
const Color DEFAULT_COLOR = Color::Red();
const Alignment DEFAULT_ALIGNMENT = Alignment::left;
} // namespace Text
namespace Renderer
{
const Color DEFAULT_RENDER_COLOR = Color::White();
}
namespace Engine
{
const int DEFAULT_FPS = 60;
const int MAX_NESTED_CHILDREN = 5; ///< The maximum amount of nested children a game object can
                                   ///< have. This is to prevent infinite recursion.
} // namespace Engine
namespace Debug
{
const bool EnableDebug = true;
const bool DrawColliders = true;
const bool DrawNodes = true;
} // namespace Debug

namespace Audio
{

/**
 * The maximum amount of instances that can be played at the same time.
 * Current limit is set to the max amount of SFML instances
 */
const int AUDIO_MAX_INSTANCE_COUNT = 255;
} // namespace Audio

namespace Pathfinding
{
/**
 * @brief The maximum distance between two nodes on a pathfindable object.
 */
const int NODE_SPACING = 10;
} // namespace Pathfinding

} // namespace CoreConstants

#endif // DEFUNBOBENGINE_CORECONSTANTS_HPP
