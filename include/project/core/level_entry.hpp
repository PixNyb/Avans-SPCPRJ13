/**
 * @file level_entry.hpp
 * @author "Melvin van Bree"
 * @brief A file containing the LevelEntry class.
 * @version 0.1
 * @date 15/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_ENTRY_HPP
#define DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_ENTRY_HPP

#include "level_type.hpp"
#include <map>
#include <string>

struct LevelEntry
{
  private:
    std::map<std::string, std::string> _additionalAttributes; ///< The level data.
  public:
    unsigned long long levelID; ///< The level ID.
    std::string levelName;      ///< The level name.
    LevelType levelType;        ///< The level type.

    /**
     * @brief Construct a new Level Entry object.
     */
    LevelEntry() : levelID(0), levelName(""), levelType(LevelType::File) {}

    /**
     * @brief Construct a new Level Entry object.
     * @param levelID The level ID.
     * @param levelName The level name.
     * @param levelType The level type.
     */
    LevelEntry(unsigned long long levelID, std::string levelName, LevelType levelType)
        : levelID(levelID), levelName(std::move(levelName)), levelType(levelType)
    {
    }

    void SetAdditionalAttribute(const std::string &key, const std::string &value)
    {
        _additionalAttributes[key] = value;
    }

    [[nodiscard]] bool HasAdditionalAttribute(const std::string &key) const
    {
        return _additionalAttributes.find(key) != _additionalAttributes.end();
    }

    [[nodiscard]] std::string GetAdditionalAttribute(const std::string &key) const
    {
        return _additionalAttributes.at(key);
    }
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_ENTRY_HPP
