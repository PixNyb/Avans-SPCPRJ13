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
#include "time.hpp"

Animator::Animator() : currentState(nullptr) {}

Animator::Animator(const Animator &other) : BehaviourScript(other)
{
    // Copy constructor implementation
    this->hasStarted = other.hasStarted;
    if (other.currentState)
    {
        this->currentState = std::make_unique<AnimationState>(*other.currentState);
    }
    this->states = other.states;
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

[[gnu::used]] void Animator::AddState(const std::string &name, const AnimationState &state)
{
    states[name] = state;
}

[[gnu::used]] void Animator::SetState(const std::string &name)
{
    auto it = states.find(name);
    if (it != states.end())
    {
        currentState = std::make_unique<AnimationState>(it->second);
    }
}

void Animator::OnUpdate()
{
    if (currentState)
    {
        currentState->Update(Time::GetDeltaTime());
    }
}

int Animator::GetCurrentFrameIndex() const
{
    if (currentState)
    {
        return currentState->GetCurrentFrameIndex();
    }
    return 0;
}

std::shared_ptr<Component> Animator::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Animator>(*this);
}
