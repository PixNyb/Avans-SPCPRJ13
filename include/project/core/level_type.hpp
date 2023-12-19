/**
 * @file level_type.hpp
 * @author "Melvin van Bree"
 * @brief A file containing the level_type class.
 * @version 0.1
 * @date 15/12/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_TYPE_HPP
#define DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_TYPE_HPP

/**
 * @enum LevelType
 * @brief The type of a level.
 */
enum class LevelType
{
    File,         ///< A level which is stored in a file.
    SceneInstance ///< A level which is a scene instance.
};

#endif // DEFUNBOBENGINE_INCLUDE_PROJECT_CORE_LEVEL_TYPE_HPP
