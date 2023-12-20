/**
 * @file level_entry.cpp
 * @author "Melvin van Bree"
 * @brief A file containing the LevelEntry class.
 * @version 0.1
 * @date 15/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "level_entry.hpp"

LevelEntry::LevelEntry(unsigned long long int levelID, std::string levelName, LevelType levelType)
    : levelID(levelID), levelName(std::move(levelName)), levelType(levelType)
{
}
void LevelEntry::SetAdditionalAttribute(const std::string &key, const std::string &value)
{
    _additionalAttributes[key] = value;
}
bool LevelEntry::HasAdditionalAttribute(const std::string &key) const
{
    return _additionalAttributes.find(key) != _additionalAttributes.end();
}
std::string LevelEntry::GetAdditionalAttribute(const std::string &key) const
{
    return _additionalAttributes.at(key);
}
