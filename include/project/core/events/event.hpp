/**
 * @file event.hpp
 * @author Robin Pijnappels
 * @brief This file contains the Event class definition.
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

#include "event_type.hpp"
#include "SDL.h"

/**
 * @class Event
 * @brief Base class for events in the game engine.
 *
 * Event serves as a base class for all types of events. It contains a member that
 * specifies the type of event, allowing event handlers to process it accordingly.
 */
class Event {
public:
    /**
     * @brief Constructs an event with a specified type.
     * @param type The type of the event.
     * @param scancode Scancode of the key (or other relevant information).
     */
    explicit Event(Uint32 type) : type(type) {}

    /**
     * @brief Virtual destructor for polymorphic deletion.
     */
    virtual ~Event() = default;

    [[nodiscard]] Uint32 getType() const { return type; };

    // Ordering the enums
    bool operator<(const Event& other) const { return type < other.type; }

private:
    Uint32 type; ///< The type of the event.
};

#endif //DEFUNBOBENGINE_EVENT_HPP
