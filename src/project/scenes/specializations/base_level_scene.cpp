/**
 * @file base_level_scene.cpp
 * @author melvi
 * @brief Provides specialization for levels.
 * @version 0.1
 * @date 08/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "base_level_scene.hpp"

BaseLevelScene::BaseLevelScene(int id)
{
    this->id = id;
}

BaseLevelScene::~BaseLevelScene()
{
}

void BaseLevelScene::RenderScene()
{
}

void BaseLevelScene::UpdateScene()
{
}

void BaseLevelScene::StartLevel()
{
}

void BaseLevelScene::StopLevel()
{
}

void BaseLevelScene::LoadLevel(std::string& content)
{
}

int BaseLevelScene::GetId() const
{
    return id;
}