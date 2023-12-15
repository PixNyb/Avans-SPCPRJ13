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
#include <string>

struct LevelEntry
{
  public:
    unsigned long long levelID; ///< The level ID.
    std::string levelName;      ///< The level name.
    LevelType levelType;        ///< The level type.
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_ENTRY_HPP
