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
#include "engine.hpp"
#include "physics_manager.hpp"
#include "time.hpp"

Animator::Animator(const Animator &other) : BehaviourScript(other)
{
    // Copy constructor implementation
    this->hasStarted = other.hasStarted;
    if (other.currentState)
    {
        this->currentState = std::make_unique<AnimationState>(*other.currentState);
    }
    this->states = other.states;
    this->totalColumns = other.totalColumns;
    this->totalRows = other.totalRows;
}

void Animator::AddState(const std::string &name, const AnimationState &state)
{
    states[name] = state;
}

void Animator::SetState(const std::string &name)
{
    auto it = states.find(name);
    if (it != states.end())
    {
        currentState = std::make_unique<AnimationState>(it->second);
    }
}

void Animator::OnUpdate()
{
    auto physicsManager = Engine::GetInstance()->Get<PhysicsManager>();
    auto velocity = physicsManager->GetVelocity(gameObject.lock());
    if (velocity.x != 0 || velocity.y != 0)
    {
        if (currentState)
        {
            currentState->Update(Time::GetDeltaTime());
        }
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
    auto object = std::make_shared<Animator>(*this);
    object->SetGameObject(parent);
    return object;
}

int Animator::GetTotalColumns() const { return totalColumns; }

int Animator::GetTotalRows() const { return totalRows; }
