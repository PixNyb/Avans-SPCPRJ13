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
#include <fmt/core.h>
#include <stdexcept>

PrefabManager::PrefabManager() : prefabs()
{}

void PrefabManager::RegisterPrefab(const std::string& tag, const GameObject& prefab)
{
    prefabs.insert(std::pair(tag, prefab));
}

GameObject PrefabManager::GetPrefab(std::string tag)
{
    auto it = prefabs.find(tag);

    if (it == prefabs.end())
        throw std::runtime_error(fmt::format("No prefab was found matching the tag: {}", tag).c_str());

    return GameObject(it->second);
}

bool PrefabManager::HasPrefab(const std::string& tag) const
{
    auto it = prefabs.find(tag);

    return it != prefabs.end();
}

void PrefabManager::RemovePrefab(const std::string& tag)
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