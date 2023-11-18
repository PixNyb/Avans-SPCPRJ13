#include "action_type.hpp"

ActionType::ActionType(std::string enumName) : enumName(std::move(enumName)) {
    setDefaultEnums();
}

std::unordered_map<std::string, ActionType> ActionType::stringToEnumMap;

const ActionType ActionType::NONE("NONE");
const ActionType ActionType::JUMP("JUMP");
const ActionType ActionType::PAUSE("PAUSE");
const ActionType ActionType::GOLEFT("GOLEFT");
const ActionType ActionType::GORIGHT("GORIGHT");
const ActionType ActionType::GOUP("GOUP");
const ActionType ActionType::GODOWN("GODOWN");

//// Initialize the map
void ActionType::setDefaultEnums() {
    for(const auto& actionTypePair : ActionType::stringToEnumMap) {
        stringToEnumMap.emplace(actionTypePair.second.enumName, actionTypePair.first);
    }
}

ActionType ActionType::convertStringToEnum(std::string enumName) {
    std::transform(enumName.begin(), enumName.end(), enumName.begin(), ::toupper);

    auto it = stringToEnumMap.find(enumName);
    ActionType enumValue = ActionType::NONE;

    if(it != stringToEnumMap.end()) {
        enumValue = it->second;
    }
    else {
        stringToEnumMap.emplace(enumName, ActionType{enumName});
        enumValue = stringToEnumMap.at(enumName);
    }

    return enumValue;
}

std::string ActionType::getName() const {
    return enumName;
}

bool ActionType::operator<(const ActionType& other) const {
    return enumName < other.enumName;
}

bool ActionType::operator==(const ActionType& other) const {
    return enumName == other.enumName;
}
