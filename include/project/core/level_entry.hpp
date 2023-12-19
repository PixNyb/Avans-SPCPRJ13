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

/**
 * @class LevelEntry
 * @brief An entry-level class for holding level details in a game.
 */
struct LevelEntry
{
  private:
    std::map<std::string, std::string>
        _additionalAttributes; ///< Private member holding level data.

  public:
    unsigned long long levelID; ///< Public member holding unique level ID.
    std::string levelName;      ///< Public member holding level name.
    LevelType levelType;        ///< Public member holding type of level.

    /**
     * @brief Default constructor for LevelEntry class initializes levelID, levelName, and
     * levelType.
     */
    LevelEntry() : levelID(0), levelName(""), levelType(LevelType::File) {}

    /**
     * @brief Parametrized constructor for LevelEntry class initializes levelID, levelName, and
     * levelType based on passed arguments.
     * @param levelID Unique ID of the level.
     * @param levelName Name of the level.
     * @param levelType Type of the level.
     */
    LevelEntry(unsigned long long levelID, std::string levelName, LevelType levelType);

    /**
     * @brief Function to set additional attribute to level.
     * @param key Key of the attribute.
     * @param value Value of the attribute.
     */
    void SetAdditionalAttribute(const std::string &key, const std::string &value);

    /**
     * @brief Function to check if additional attribute exists in level.
     * @param key Key of the attribute.
     * @return boolean value indicating presence or absence of attribute.
     */
    [[nodiscard]] bool HasAdditionalAttribute(const std::string &key) const;

    /**
     * @brief Function to get additional attribute from level.
     * @param key Key of the attribute.
     * @return Value of the attribute.
     */
    [[nodiscard]] std::string GetAdditionalAttribute(const std::string &key) const;
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_ENTRY_HPP