/**
 * @file level_manager.cpp
 * @author Maxuuuu
 * @brief Implementation of the LevelManager.
 * @version 0.1
 * @date 21/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#include "level_manager.hpp"
#include "behaviour_script_manager.hpp"
#include "engine.hpp"
#include "level_name_generator.hpp"
#include "pathfinding_manager.hpp"
#include "physics_manager.hpp"
#include <filesystem>
#include <fmt/format.h>
#include <iostream>
#include <regex>
#include <utility>

LevelManager::LevelManager(std::shared_ptr<SceneManager> &sManager,
                           std::shared_ptr<PrefabManager> &pManager,
                           std::shared_ptr<JSONHandler> &jHandler)
    : levels(), sceneManager(sManager), prefabManager(pManager),
      levelFactory(std::make_unique<LevelFactory>(pManager)), jsonHandler(jHandler),
      levelFileExtension(".json")
{
}

LevelManager::~LevelManager() = default;

void LevelManager::RegisterLevel(int id, std::string filePath)
{
    auto path = std::filesystem::absolute(filePath).string();
    // Check if file exists.
    if (!std::filesystem::exists(path))
        throw std::runtime_error(fmt::format("No file was found at: '{}'", filePath));

    // Check for file extension.
    if (filePath.length() < levelFileExtension.length() ||
        (0 != filePath.compare(filePath.length() - levelFileExtension.length(),
                               levelFileExtension.length(), levelFileExtension)))
        throw std::runtime_error(fmt::format(
            "Level file is of a unsupported type. Expected type: '{}'", levelFileExtension));

    if (levels.find(id) != levels.end())
        throw std::runtime_error(fmt::format("Level with id '{}' already exists.", id));

    levels.insert(std::pair(id, filePath));
}

void LevelManager::LoadLevel(int id)
{
    Engine::GetInstance()->Get<PathfindingManager>()->EnablePathfinding();
    Engine::GetInstance()->Get<BehaviourScriptManager>()->shouldExecute = true;
    currentLevelID = id;
    auto scene = CreateScene(id);
    // Update the current scene.
    sceneManager->SetScene(scene);
    // Update the physics.
    Engine::GetInstance()->Get<PhysicsManager>()->CreateWorld(scene->contents);
}

std::shared_ptr<Scene> LevelManager::CreateScene(int id)
{
    auto path = levels.find(id);

    // No level found with the following id.
    if (path == levels.end())
        throw std::runtime_error(fmt::format("No level found with id: '{}'", id));

    try
    {
        // Read level JSON.
        auto levelJson = jsonHandler->ConvertFileToJson(path->second);
        // Create level based on the JSON.
        auto level = levelFactory->CreateScene(levelJson);

        return level;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        throw std::runtime_error(fmt::format("Could not load level with id: '{}'", id));
    }
}

void LevelManager::LoadLevel(LevelEntry &levelEntry)
{
    Engine::GetInstance()->Get<PathfindingManager>()->EnablePathfinding();

    if (levelEntry.levelType == LevelType::File)
    {
        LoadLevel(static_cast<int>(levelEntry.levelID));
        return;
    }

    if (levelEntry.levelType == LevelType::SceneInstance)
    {
        try
        {
            auto [name, factory] = _levelScenes[levelEntry.levelID];
            sceneManager->SetScene(factory());
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        return;
    }

    throw std::runtime_error("Could not load level!");
}

std::string LevelManager::SaveLevelFromScene(std::string &directory, std::string &filename)
{
    auto currentWeakScene = sceneManager->GetScene();

    if (currentWeakScene.expired())
        throw std::runtime_error("No scene is currently loaded.");

    auto currentScene = currentWeakScene.lock();
    auto camera = currentScene->GetCamera();

    return SaveLevel(directory, filename, camera, currentScene->contents);
}

std::string LevelManager::SaveNewLevel(const std::string &directory,
                                       const std::shared_ptr<Camera> &camera,
                                       const std::vector<std::shared_ptr<GameObject>> &gameObjects)
{
    // Get the highest ID and add 1 to it.
    auto currentHighestId = std::max_element(levels.begin(), levels.end())->first;

    auto name = LevelNameGenerator::Generate(currentHighestId + 1) + levelFileExtension;

    return SaveLevel(directory, name, camera, gameObjects);
}

std::string LevelManager::SaveLevel(const std::string &directory, const std::string &filename,
                                    const std::shared_ptr<Camera> &camera,
                                    const std::vector<std::shared_ptr<GameObject>> &gameObjects)
{
    auto levelJson = nlohmann::json::object();

    // Convert the Camera to a json object and add it to the level json.
    auto cameraJson = CreateCameraJson(*camera);
    levelJson["camera"] = cameraJson;

    // Convert the GameObjects of the scene to json objects.
    nlohmann::json objects;
    for (const auto &gameObject : gameObjects)
    {
        // Check if the GameObject has a parent, if it does it should not be called here due
        // to only root objects needing to be in objects array. The level json has a recursive
        // structure of root components and their children. These children will be added in the
        // recursive function call.
        if (gameObject->GetParent() != nullptr)
            continue;

        auto objectJson = CreateGameObjectJson(*gameObject);
        objects.push_back(objectJson);
    }

    // Add the array of GameObjects to the level json.
    levelJson["objects"] = objects;

    // Write the json object to a file and return the resulting file path.
    auto fullPath = directory + filename;
    auto filePath = jsonHandler->WriteJsonToFile(fullPath, levelJson);

    return filePath;
}

nlohmann::json LevelManager::CreateGameObjectJson(GameObject &gameObject)
{
    auto objectJson = nlohmann::json::object();
    auto prefabId = gameObject.GetPrefabId();

    // If no prefab is registered by the prefab id, or a default value is found, an error is thrown.
    if (!prefabManager->HasPrefab(prefabId) || prefabId.empty())
        throw std::runtime_error(fmt::format("A GameObject needs to be a registered prefab "
                                             "before it can be saved. Unregistered type: '{}'",
                                             prefabId));

    // Add basic properties.
    objectJson["prefab"] = gameObject.GetPrefabId();
    objectJson["name"] = gameObject.GetName();
    objectJson["active"] = gameObject.IsActive();
    objectJson["layer"] = gameObject.GetLayer();

    // Add transform struct.
    auto transform = gameObject.GetTransform();
    objectJson["transform"] = {
        {"position", {{"x", transform.position.x}, {"y", transform.position.y}}},
        {"rotation", transform.rotation},
        {"scale", transform.scale}};

    nlohmann::json children;
    // Iterate over every child object in a recursive function call.
    for (const auto &child : gameObject.GetChildren())
    {
        // When push_back() is called the json turns into an array.
        children.push_back(CreateGameObjectJson(*child));
    }

    // The children array is added to the GameObject json.
    objectJson["children"] = children;

    return objectJson;
}

nlohmann::json LevelManager::CreateCameraJson(Camera &camera)
{
    auto cameraJson = nlohmann::json::object();

    // Add properties to the camera json.
    cameraJson["width"] = camera.GetAspectWidth();
    cameraJson["height"] = camera.GetAspectHeight();

    return cameraJson;
}

void LevelManager::LoadAllFromDirectory(const std::string &directory)
{
    // Regular expression to match the required filename format
    std::regex filenamePattern(R"((\d+)_(.*)\.json)");

    for (const auto &entry : std::filesystem::directory_iterator(directory))
    {
        if (!entry.is_regular_file())
        {
            continue;
        }

        std::smatch match;
        auto filename = entry.path().filename().string();
        if (!std::regex_match(filename, match, filenamePattern) || match.size() != 3)
        {
            std::cout << "Skipped file with invalid filename format: " << entry.path() << std::endl;
            continue;
        }

        // Extract information using capture groups
        std::string id = match[1];
        std::string name = match[2];
        std::cout << "Found match. ID: " << id << ", File: " << entry.path() << std::endl;
        // Process the JSON file
        RegisterLevel(std::stoi(id), entry.path().string());
    }
}
std::vector<LevelEntry> LevelManager::GetLevels()
{
    std::vector<LevelEntry> entries;

    for (auto const &[key, val] : levels)
    {
        auto entry = LevelEntry();
        entry.levelName = "none";

        auto path = std::filesystem::weakly_canonical(val);
        if (path.has_filename())
        {
            auto filename = path.filename().string();
            filename = filename.substr(0, filename.find_last_of('.'));
            std::replace(filename.begin(), filename.end(), '_', ' ');
            entry.levelName = filename;
        }

        entry.SetAdditionalAttribute("path", path.string());
        entry.levelID = key;
        entry.levelType = LevelType::File;
        entries.push_back(entry);
    }

    for (auto const &[key, nameFuncSet] : _levelScenes)
    {
        auto [name, factory] = nameFuncSet;

        auto entry = LevelEntry();
        entry.levelID = key;
        entry.levelName = name;
        entry.levelType = LevelType::SceneInstance;
        entries.push_back(entry);
    }

    return entries;
}

void LevelManager::SwapLevel(LevelEntry levelA, LevelEntry levelB)
{
    // Prevent swapping of non-file levels
    if (levelA.levelType != LevelType::File || levelB.levelType != LevelType::File)
    {
        return;
    }

    auto levelPathA = std::filesystem::weakly_canonical(levels[levelA.levelID]);
    auto levelPathB = std::filesystem::weakly_canonical(levels[levelB.levelID]);

    // Regular expression to match the required filename format
    std::regex filenamePattern(R"((\d+)_(.*)\.json)");

    auto fileNameA = levelPathA.filename().string();
    auto fileNameB = levelPathB.filename().string();

    // If both filenames don't match the pattern throw an error
    std::smatch matchA, matchB;
    if (!std::regex_search(fileNameA, matchA, filenamePattern) ||
        !std::regex_search(fileNameB, matchB, filenamePattern))
    {
        throw std::runtime_error("Could not swap levels.");
    }

    // Swap the IDs of the file names, format is ID_Name.json
    std::string newFilenameA = fmt::format("{}_{}.json", matchB[1].str(), matchA[2].str());
    std::string newFilenameB = fmt::format("{}_{}.json", matchA[1].str(), matchB[2].str());

    // Rename the files
    auto newFilePathA = levelPathA.parent_path() / newFilenameA;
    auto newFilePathB = levelPathB.parent_path() / newFilenameB;

    std::filesystem::rename(levelPathA, newFilePathA);
    std::filesystem::rename(levelPathB, newFilePathB);

    // Update the level paths with the swapped filepaths
    levels[levelB.levelID] = newFilePathA.string();
    levels[levelA.levelID] = newFilePathB.string();
}

int LevelManager::GetCurrentLevelID() { return currentLevelID; }

void LevelManager::DeleteLevel(LevelEntry level)
{
    if (level.levelType != LevelType::File)
        return;

    auto levelPath = std::filesystem::weakly_canonical(levels[level.levelID]);
    if (!std::filesystem::exists(levelPath))
        return;

    std::filesystem::remove(levelPath);
    levels.erase(static_cast<int>(level.levelID));
}

void LevelManager::RefreshLevels(const std::string &directory)
{
    levels.clear();
    LoadAllFromDirectory(directory);
}
