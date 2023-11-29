/**
 * @file event_type.hpp
 * @author Robin Pijnappels
 * @brief This file contains the EventType enum.
 * @version 0.1
 * @date 2023-11-08
 *
 * The EventType enum defines various types of events that can be processed by the game engine.
 * This separation of the EventType enum allows for easy expansion and usage across different
 * parts of the engine without direct dependency on the Event class itself.
 *
 */

#ifndef DEFUNBOBENGINE_EVENT_TYPE_HPP
#define DEFUNBOBENGINE_EVENT_TYPE_HPP

/**
 * @enum EventType
 * @brief Enumerates the types of events that the game engine can process.
 */
enum class EventType
{
    None,            ///< Represents no event.
    KeyPress,        ///< Represents a key press event.
    KeyRelease,      ///< Represents a key release event.
    MouseButtonDown, ///< Represents a mouse button down event.
    MouseButtonUp,   ///< Represents a mouse button up event.
    MouseMove,       ///< Represents a mouse movement event.
    WindowClose,     ///< Represents a window close event.
};

#endif // DEFUNBOBENGINE_EVENT_TYPE_HPP
