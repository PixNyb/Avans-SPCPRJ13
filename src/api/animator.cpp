/**
 * @file animator.cpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the Animator class implementation.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 */

#include "animator.hpp"

Animator::Animator()
{
    // Constructor implementation
}

Animator::Animator(const Animator &other)
 : BehaviourScript(other) {
    // Copy constructor implementation
    this->hasStarted = other.hasStarted;
    this->currentState = other.currentState;
    this->possibleStates = other.possibleStates;
}

void Animator::Update()
{
    // Implementation
}

void Animator::Stop()
{
    // Implementation
}

void Animator::Play(bool looping)
{
    // Implementation
}

std::shared_ptr<Component> Animator::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Animator>(*this);
}
