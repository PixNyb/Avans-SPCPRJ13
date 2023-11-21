/**
 * @file event.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Event class definition, a base class for events in the game engine.
 * @version 0.1
 * @date 2023-11-08
 *
 * The Event class is a base class for all events within the game engine. It holds the
 * type of the event, and specific event classes can extend it to provide additional
 * information relevant to that event type.
 *
 */

#ifndef DEFUNBOBENGINE_EVENT_HPP
#define DEFUNBOBENGINE_EVENT_HPP

#include "key_code.hpp"
#include "event_type.hpp"
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

    EventType GetEventType() const { return eventType; }

    /**
     * @brief Overloaded less-than operator for ordering events based on their types.
     * @param other The Event to compare with.
     * @return True if the type of this event is less than the type of the other event, false
     * otherwise.
     */
    bool operator<(const Event &other) const { return keyCode < other.keyCode; }

    void MarkProcessed() { isProcessed = true; }

    bool IsProcessed() const { return isProcessed; }

  private:
    KeyCode keyCode; ///< The type of the event.
    bool isProcessed = false;
    EventType eventType;
};

#endif // DEFUNBOBENGINE_EVENT_HPP
