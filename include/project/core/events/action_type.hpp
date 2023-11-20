/**
 * @file action_type.hpp
 * @author Martijn Vermeer
 * @brief This file contains the action type class definition.
 * @version 0.1
 * @date 2023-11-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_ACTION_TYPE_HPP
#define AVANS_SPCPRJ13_ACTION_TYPE_HPP

#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>

/**
 * @class ActionType
 * @brief Represents different types of actions that can be associated with input events.
 *
 * The ActionType class provides a way to define and manage various action types used
 * in a program. Each ActionType is associated with a unique string identifier.
 */
class ActionType {
public:
    /**
     * @brief Constructs an ActionType with the given string identifier.
     * @param enumName The string identifier for the ActionType.
     */
    explicit ActionType(std::string enumName);

    static const ActionType NONE;
    static const ActionType JUMP;
    static const ActionType PAUSE;
    static const ActionType GOLEFT;
    static const ActionType GORIGHT;
    static const ActionType GOUP;
    static const ActionType GODOWN;

    /**
     * @brief Converts a string identifier to the corresponding ActionType.
     * @param enumName The string identifier to convert.
     * @return The corresponding ActionType.
     */
    static ActionType convertStringToEnum(std::string enumName);

    /**
     * @brief Gets the string identifier of the ActionType.
     * @return The string identifier.
     */
    [[nodiscard]] std::string getName() const;

    /**
      * @brief Overloaded less-than operator for comparing ActionType objects.
      * @param other The ActionType to compare with.
      * @return True if this ActionType is less than the other, false otherwise.
      */
    bool operator<(const ActionType& other) const;

    /**
     * @brief Overloaded equality operator for comparing ActionType objects.
     * @param other The ActionType to compare with.
     * @return True if this ActionType is equal to the other, false otherwise.
     */
    bool operator==(const ActionType& other) const;

private:
    std::string enumName;
    static std::unordered_map<std::string, ActionType> stringToEnumMap;

    /**
     * @brief initializes the stringToEnumMap with ActionType instances.
     */
    static void setDefaultEnums();
};

#endif // AVANS_SPCPRJ13_ACTION_TYPE_HPP
