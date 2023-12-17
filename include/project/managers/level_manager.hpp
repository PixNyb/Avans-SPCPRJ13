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

#include "json_handler.hpp"
#include "level_entry.hpp"
#include "level_factory.hpp"
#include "scene_manager.hpp"
#include <fmt/format.h>
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
     * @brief A map consisting of level id's and a filepath to the corresponding level JSON.
     * @key The hashcode of the scene class.
     * @value A name mapped to a scene factory method.
     */
    std::map<size_t, std::tuple<std::string, std::function<std::shared_ptr<Scene>()>>>
        _levelScenes; ///< All level scenes. Provides additional ways to add levels.

    /**
     * @brief A SceneManager which can be used to load the level.
     */
    std::shared_ptr<SceneManager> sceneManager;

    /**
     * @brief A PrefabManager which can be used to identify the prefabs from a level.
     */
    std::shared_ptr<PrefabManager> prefabManager;

    /**
     * @brief A LevelFactory which is used to load the level.
     */
    std::unique_ptr<LevelFactory> levelFactory;

    /**
     * @brief A JSONHandler which is used to read the level JSON files.
     */
    std::shared_ptr<JSONHandler> jsonHandler;

    /**
     * @brief The file extension used for the level files.
     */
    std::string levelFileExtension;

    /**
     * @brief Create a json object from a GameObject.
     * @param gameObject The GameObject which is to converted.
     * @return The json of the given GameObject.
     */
    nlohmann::json CreateGameObjectJson(GameObject &gameObject);

    /**
     * @brief Create a json object from a Camera.
     * @param camera The camera which is to be converted.
     * @return The json of the given Camera.
     */
    nlohmann::json CreateCameraJson(Camera &camera);

  public:
    /**
     * @brief Construct a new LevelManager;
     */
    LevelManager(std::shared_ptr<SceneManager> &sManager, std::shared_ptr<PrefabManager> &pManager,
                 std::shared_ptr<JSONHandler> &jReader);

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
     * @brief Registers a level.
     * @tparam T The type of the scene. Name and hashcode are inferred from it.
     * @param instanceFactory The instance factory of the scene.
     */
    template <typename T>
    void RegisterScene(std::function<std::shared_ptr<Scene>()> instanceFactory)
    {
        _levelScenes[typeid(T).hash_code()] = {typeid(T).name(), std::move(instanceFactory)};
    }

    /**
     * @brief Create a scene based on the provided id.
     * @param id The id of which scene is to be created.
     * @return The scene which is created.
     */
    std::shared_ptr<Scene> CreateScene(int id);

    /**
     * @brief Load a level based on the provided id.
     * @param id The id of which level is to be loaded.
     */
    void LoadLevel(int id);

    /**
     * @brief Load a level based on the provided id.
     * @param levelEntry
     */
    void LoadLevel(LevelEntry &levelEntry);

    /**
     * @brief Load a levels into the dictionary based on the directory.
     * @param directory The directory of where the level JSON can be found.
     */
    void LoadAllFromDirectory(const std::string &directory);

    /**
     * @brief Save the level by the current scene. The intended use is saving a level made.
     * using level editor.
     * @param directory The directory to where the level json is to be saved.
     * @param filename The eventual filename.
     * @return The path of where the level is stored.
     */
    std::string SaveLevel(std::string &directory, std::string &filename);

    /**
     * @brief Save the level by a list of game objects.
     * @param directory The directory to where the level json is to be saved.
     * @param filename The eventual filename.
     * @param gameObjects The list of game objects which are to be saved.
     * @return The path of where the level is stored.
     */
    std::string SaveLevel(std::string &directory, std::string &filename,
                          std::shared_ptr<Camera> &camera,
                          std::vector<std::shared_ptr<GameObject>> &gameObjects);

    /**
     * @brief Get the Level id's and file paths.
     * @return A map consisting of level id's and file paths.
     */
    std::vector<LevelEntry> GetLevels();

    /**
     * @brief Swaps two file levels.
     * @param levelIDa levelIDa
     * @param levelIDb levelIDb
     *
     * @note Can only swap File levels.
     */
    void SwapLevel(LevelEntry levelA, LevelEntry levelB);
};

#endif // DEFUNBOBENGINE_LEVEL_MANAGER_HPP
