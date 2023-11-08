//
// Created by Robin Pijnappels on 08/11/2023.
//

#ifndef DEFUNBOBENGINE_EVENT_HPP
#define DEFUNBOBENGINE_EVENT_HPP

enum class EventType {
    None,
    KeyPress,
    KeyRelease,
    MouseButtonDown,
    MouseButtonUp,
    MouseMove,
    WindowClose,
};

class Event {
        public:
        EventType type;

        Event(EventType type) : type(type) {}

        virtual ~Event() {}
};

#endif //DEFUNBOBENGINE_EVENT_HPP
