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

AnimationState::AnimationState(int totalFrames, float frameTime)
        : totalFrames(totalFrames), frameTime(frameTime), currentFrame(0), elapsedTime(0.0f) {}

void AnimationState::Update(float deltaTime) {
    elapsedTime += deltaTime;
    if (elapsedTime >= frameTime) {
        currentFrame = (currentFrame + 1) % totalFrames;
        elapsedTime -= frameTime;
    }
}

int AnimationState::GetCurrentFrame() const {
    return currentFrame;
}
