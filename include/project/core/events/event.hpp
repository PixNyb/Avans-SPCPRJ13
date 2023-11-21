/**
 * @file event.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Event class definition, a base class for events in the game engine.
 * @version 0.1
 * @date 2023-11-08
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_EVENT_HPP
#define DEFUNBOBENGINE_EVENT_HPP

#include "event_type.hpp"
#include "key_code.hpp"
#include <cstdint>

/**
 * @class Event
 * @brief Base class for events in the game engine.
 *
 * Event serves as a base class for all types of events. It contains a member that
 * specifies the type of event, allowing event handlers to process it accordingly.
 */
class Event
{
  public:
    /**
     * @brief Constructs an event with a specified type.
     * @param type The type of the event.
     * @param scancode Scancode of the key (or other relevant information).
     */
    explicit Event(KeyCode keyCode, EventType eventType) : keyCode(keyCode), eventType(eventType) {}

    /**
     * @brief Virtual destructor for polymorphic deletion.
     */
    virtual ~Event() = default;

    /**
     * @brief Retrieves the type of the event.
     * @return The type of the event as a Uint32 value.
     */
    KeyCode GetKeyCode() const { return keyCode; };

    /**
     * @brief Retrieves the type of the event.
     * @return The type of the event.
     */
    EventType GetEventType() const { return eventType; }

    /**
     * @brief Overloaded less-than operator for ordering events based on their types.
     * @param other The Event to compare with.
     * @return True if the type of this event is less than the type of the other event, false
     * otherwise.
     */
    bool operator<(const Event &other) const { return keyCode < other.keyCode; }

    /**
     * @brief Marks the event as processed.
     */
    void MarkProcessed() { isProcessed = true; }

    /**
     * @brief Checks if the event has been processed.
     * @return True if the event has been processed, false otherwise.
     */
    bool IsProcessed() const { return isProcessed; }

  private:
    KeyCode keyCode;          ///< The key code associated with the event.
    bool isProcessed = false; ///< The type of the event.
    EventType eventType;      ///< Flag indicating whether the event has been processed.
};

#endif // DEFUNBOBENGINE_EVENT_HPP
