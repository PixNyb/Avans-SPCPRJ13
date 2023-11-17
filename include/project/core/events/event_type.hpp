///**
// * @file event_type.hpp
// * @author Robin Pijnappels
// * @brief This file contains the EventType enum.
// * @version 0.1
// * @date 2023-11-08
// *
// * The EventType enum defines various types of events that can be processed by the game engine.
// * This separation of the EventType enum allows for easy expansion and usage across different
// * parts of the engine without direct dependency on the Event class itself.
// *
// */
//
//#ifndef DEFUNBOBENGINE_EVENT_TYPE_HPP
//#define DEFUNBOBENGINE_EVENT_TYPE_HPP
//
//#include "unordered_map"
//#include <string>
//
///**
// * @enum EventType
// * @brief Enumerates the types of events that the game engine can process.
// */
//class EventType {
//public:
//    EventType(std::string value) : name(std::move(value)) {}
//
//    static const EventType None;           ///< Represents no event
//    static const EventType KeyPress;       ///< Represents a key press event.
//    static const EventType KeyRelease;     ///< Represents a key release event.
//    static const EventType MouseButtonDown;///< Represents a mouse button down event.
//    static const EventType MouseButtonUp;  ///< Represents a mouse button up event.
//    static const EventType MouseMove;      ///< Represents a mouse movement event.
//    static const EventType WindowClose;    ///< Represents a window close event.
//
//    [[nodiscard]] const std::string& getValue() const { return name; }
//
//    static EventType convertStringToEnum(const std::string& enumName) {
//        auto it = stringToEnumMap.find(enumName);
//        EventType enumValue = EventType::None;
//
//        if(it != stringToEnumMap.end()) {
//            enumValue = it->second;
//        }
//        else {
//            stringToEnumMap.emplace(enumName, EventType{enumName});
//            enumValue = stringToEnumMap.at(enumName);
//        }
//
//        return enumValue;
//    }
//
//    // Ordering the enums
//    bool operator<(const EventType& other) const {
//        return name < other.name;
//    }
//
//private:
//    std::string name;
//    static std::unordered_map<std::string, EventType> stringToEnumMap;
//};
//
//#endif //DEFUNBOBENGINE_EVENT_TYPE_HPP
