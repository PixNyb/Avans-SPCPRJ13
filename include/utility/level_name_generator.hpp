/**
 * @file level_name_generator.hpp
 * @author "Melvin van Bree"
 * @brief A file containing the LevelNameGenerator class.
 * @version 0.1
 * @date 19/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_UTILITY_LEVEL_NAME_GENERATOR_HPP
#define DEFUNBOBENGINE_INCLUDE_UTILITY_LEVEL_NAME_GENERATOR_HPP

#include <string>

/**
 * @class LevelNameGenerator
 * @brief A class for generating level names.
 */
class LevelNameGenerator
{
  public:
    /**
     * @brief Generates a level name based on the given id.
     * @param id The id of the level.
     * @return The generated level name.
     */
    static std::string Generate(int id);
};

#endif // DEFUNBOBENGINE_INCLUDE_UTILITY_LEVEL_NAME_GENERATOR_HPP
