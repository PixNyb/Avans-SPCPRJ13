/**
 * @file load_level_behaviour.cpp
 * @author Maxuuuu
 * @brief Implementation of the LoadLevelBehaviour component.
 * @version 0.1
 * @date 22/11/2023
 *
 * @copyright Copyright (c) 2023
 */

#include "load_level_behaviour.hpp"

void LoadLevelBehaviour::OnStart()
{
    this->hasStarted = true;
}

void LoadLevelBehaviour::OnUpdate()
{
    this->levelManager->LoadLevel(levelId);
}

LoadLevelBehaviour::LoadLevelBehaviour(std::shared_ptr<LevelManager> &manager, int id) : levelManager(manager), levelId(id)
{}
