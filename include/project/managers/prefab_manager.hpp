/**
 * @file prefab_manager.hpp
 * @author Maxuuuu
 * @brief Manages prefabs
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_PREFAB_MANAGER_HPP
#define DEFUNBOBENGINE_PREFAB_MANAGER_HPP

#include "game_object.hpp"
#include <map>
#include <string>

class PrefabManager
{
  private:
    /**
     * @brief A map consisting of prefabs and the id's which they are identified by.
     */
    std::map<std::string, std::shared_ptr<GameObject>>
        prefabs; ///< The key is a unique id which can be used to identify a prefab,
                 ///< the value is the prefab.

  public:
    /**
     * @brief Construct a new PrefabManager.
     */
    PrefabManager();

    /**
     * @brief Registers a prefab.
     * @param id The unique key that can later be used to retrieve the prefab.
     * @param prefab The prefab that is to be registered.
     */
    void RegisterPrefab(const std::string &id, const std::shared_ptr<GameObject> &prefab);

    /**
     * @brief Gets a prefab based on a id.
     * @param id Defines which prefab is meant to be returned.
     * @return Returns the prefab that matches the provided id.
     */
    std::shared_ptr<GameObject> GetPrefab(std::string id);

    /**
     * @brief Check if there is a prefab registered with a specified id.
     * @param id Defines which id to check for.
     * @return True if there is already a prefab registered by the specified id.
     */
    bool HasPrefab(const std::string &id) const;

    /**
     * @brief Removes a prefab based on the specified id.
     * @param id Specifies which prefab is too be removed.
     */
    void RemovePrefab(const std::string &id);

    /**
     * @brief Clears all of the currently registered prefabs.
     */
    void ClearPrefabs();
};

#endif // DEFUNBOBENGINE_PREFAB_MANAGER_HPP
