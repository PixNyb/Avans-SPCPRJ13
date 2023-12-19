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

class LevelNameGenerator
{
  public:
    static std::string Generate(int id);
};

#endif // DEFUNBOBENGINE_INCLUDE_UTILITY_LEVEL_NAME_GENERATOR_HPP
