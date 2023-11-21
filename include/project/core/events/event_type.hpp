/**
 * @file event_type.hpp
 * @author Martijn Vermeer
 * @brief This file contains the event type code class definition.
 * @version 0.1
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_EVENT_TYPE_HPP
#define DEFUNBOBENGINE_EVENT_TYPE_HPP

/**
 * @class EventType
 * @brief Enumerates the possible actions that can be performed in a game.
 *
 * The EventType enum class defines a set of key and mouse events that a game entity can handle.
 */
enum class EventType
{
    KEYPRESSED,    ///< A key is pressed.
    KEYRELEASED,   ///< A key is released.
    MOUSEPRESSED,  ///< A mouse button is pressed.
    MOUSECLICKED,  ///< A mouse button is clicked.
    MOUSERELEASED, ///< A mouse button is released.
    MOUSEMOVED,    ///< The mouse is moved.
};

#endif // DEFUNBOBENGINE_EVENT_TYPE_HPP
