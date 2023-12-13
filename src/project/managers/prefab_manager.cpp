/**
 * @file prefab_manager.cpp
 * @author Maxuuuu
 * @brief Implementation of the prefab manager.
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#include "prefab_manager.hpp"
#include "game_object.hpp"
#include <fmt/format.h>
#include <stdexcept>

PrefabManager::PrefabManager() : prefabs() {}

void PrefabManager::RegisterPrefab(const std::string &id, const std::shared_ptr<GameObject> &prefab)
{
    // Set the tag of the prefab equal to the id under which it is stored so that it is identifiable
    // when saving a level.
    prefab->SetPrefabId(id);

    prefabs.insert(std::pair(id, prefab));
}

std::shared_ptr<GameObject> PrefabManager::GetPrefab(std::string id)
{
    auto it = prefabs.find(id);

    if (it == prefabs.end())
        throw std::runtime_error(fmt::format("No prefab was found matching the id: {}", id));

    return it->second->Clone();
}

bool PrefabManager::HasPrefab(const std::string &id) const
{
    auto it = prefabs.find(id);

    return it != prefabs.end();
}

void PrefabManager::RemovePrefab(const std::string &id)
{
    auto it = prefabs.find(id);

    if (it == prefabs.end())
        return;

    prefabs.erase(it);
}

void PrefabManager::ClearPrefabs() { prefabs.clear(); }