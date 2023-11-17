#ifndef AVANS_SPCPRJ13_ACTION_TYPE_HPP
#define AVANS_SPCPRJ13_ACTION_TYPE_HPP

#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>

class ActionType {
public:
    explicit ActionType(std::string enumName);

    static const ActionType NONE;
    static const ActionType JUMP;
    static const ActionType PAUSE;
    static const ActionType GOLEFT;
    static const ActionType GORIGHT;
    static const ActionType GOUP;
    static const ActionType GODOWN;

    static ActionType convertStringToEnum(std::string enumName);

    [[nodiscard]] std::string getName() const;

    bool operator<(const ActionType& other) const;
    bool operator==(const ActionType& other) const;

private:
    std::string enumName;
    static std::unordered_map<std::string, ActionType> stringToEnumMap;

    static void setDefaultEnums();
};

#endif // AVANS_SPCPRJ13_ACTION_TYPE_HPP
