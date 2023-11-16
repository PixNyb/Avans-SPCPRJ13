/**
 * @file prefab_manager.cpp
 * @author Maxuuuu
 * @brief Implementation of the prefab manager.
 * @version 0.1
 * @date 14/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#include "../../../include/project/managers/prefab_manager.hpp"
#include "format"

PrefabManager::PrefabManager() : prefabs()
{}

void PrefabManager::RegisterPrefab(std::string tag, GameObject prefab)
{
    prefabs.insert(std::pair(tag, prefab));
}

GameObject PrefabManager::GetPrefab(std::string tag)
{
    auto it = prefabs.find(tag);

    if (it == prefabs.end())
        throw std::exception(std::format("No prefab was found matching the tag: {0}", tag).c_str());

    return GameObject(it->second);
}

bool PrefabManager::HasPrefab(std::string tag) const
{
    auto it = prefabs.find(tag);

    return it != prefabs.end();
}

void PrefabManager::RemovePrefab(std::string tag)
{
    auto it = prefabs.find(tag);

    if (it == prefabs.end())
        return;

    prefabs.erase(it);
}

void PrefabManager::ClearPrefabs()
{
    prefabs.clear();
}