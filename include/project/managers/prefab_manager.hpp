/**
 * @file prefab_manager.hpp
 * @author Max Groenendaal
 * @brief Manages prefabs
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_PREFAB_MANAGER_HPP
#define DEFUNBOBENGINE_PREFAB_MANAGER_HPP

#include "../../api/game_object.hpp"
#include <map>
#include <string>

class PrefabManager {
  private:
    std::map<std::string, GameObject> prefabs;

  public:
    PrefabManager();

    /**
     * @brief Registers a prefab.
     * @param tag The unique key that can later be used to retrieve the prefab.
     * @param prefab The prefab that is to be registered.
     */
    void RegisterPrefab(std::string tag, GameObject prefab);

    /**
     * @brief Gets a prefab based on a tag.
     * @param tag Defines which prefab is meant to be returned.
     * @return Returns the prefab that matches the provided tag.
     */
    GameObject GetPrefab(std::string tag);

    /**
     * @brief Check if there is a prefab registered with a specified tag.
     * @param tag Defines which tag to check for.
     * @return True if there is already a prefab registered by the specified tag.
     */
    bool HasPrefab(std::string tag) const;

    /**
     * @brief Removes a prefab based on the specified tag.
     * @param tag Specifies which prefab is too be removed.
     */
    void RemovePrefab(std::string tag);

    /**
     * @brief Clears all of the currently registered prefabs.
     */
    void ClearPrefabs();
};

#endif // DEFUNBOBENGINE_PREFAB_MANAGER_HPP
