/**
 * @file level_manager.hpp
 * @author Maxuuuu
 * @brief Manages levels
 * @version 0.1
 * @date 21/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_LEVEL_MANAGER_HPP
#define DEFUNBOBENGINE_LEVEL_MANAGER_HPP

#include "json_reader.hpp"
#include "level_factory.hpp"
#include "scene_manager.hpp"
#include <map>
#include <memory>
#include <string>

/**
 * @class LevelManager
 * @brief Manages the levels of the game.
 *
 * This class is responsible for keeping track of all of the levels.
 * In addition, it can load a pre-defined level.
 */
class LevelManager
{
  private:
    /**
     * @brief A map consisting of level id's and a filepath to the corresponding level JSON.
     * @key A unique id which is used to identify a level.
     * @value A filepath leading to a level JSON file.
     */
    std::map<int, std::string> levels;

    /**
     * @brief A SceneManager which can be used to load the level.
     */
    std::shared_ptr<SceneManager> sceneManager;

    /**
     * @brief A LevelFactory which is used to load the level.
     */
    std::unique_ptr<LevelFactory> levelFactory;

    /**
     * @brief A JSONReader which is used to read the level JSON files.
     */
    std::shared_ptr<JSONReader> jsonReader;

    /**
     * @brief The file extension used for the level files.
     */
    std::string levelFileExtension;

  public:
    /**
     * @brief Construct a new LevelManager;
     */
    LevelManager(std::shared_ptr<SceneManager> &sManager, std::shared_ptr<PrefabManager> &pManager,
                 std::shared_ptr<JSONReader> &jReader);

    /**
     * @brief Deconstructs a LevelManager;
     */
    ~LevelManager();

    /**
     * @brief Registers a level.
     * @param id The unique id that is used to identify the level.
     * @param filePath The filepath of where the level JSON can be found.
     */
    void RegisterLevel(int id, std::string filePath);

    /**
     * @brief Load a level based on the provided id.
     * @param id The id of which level is to be loaded.
     */
    void LoadLevel(int id);

    /**
     * @brief Save the level which is current scene. The intended use is saving a level made using
     * level editor.
     * @return The path of where the level is stored.
     */
    std::string SaveLevel();
};

#endif // DEFUNBOBENGINE_LEVEL_MANAGER_HPP
