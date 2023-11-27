/**
 * @file animation_state.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the AnimationState class implementation.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 */

#include "animation_state.hpp"
#include "game_object.hpp"

AnimationState::AnimationState() {}

void AnimationState::Update(GameObject &gameObject) {}

void AnimationState::Update(float deltaTime)
{
    elapsedTime += deltaTime;
    if (elapsedTime >= frameDuration)
    {
        elapsedTime = 0;
        currentFrameIndex++;
        if (currentFrameIndex > endFrameIndex)
        {
            currentFrameIndex = startFrameIndex;
        }
    }
}

int AnimationState::GetCurrentFrameIndex() const { return currentFrameIndex; }

float AnimationState::GetTotalDuration() const
{
    return (endFrameIndex - startFrameIndex + 1) * frameDuration;
}