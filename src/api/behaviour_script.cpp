//
// Created by Robin Pijnappels on 31/10/2023.
//

#include "behaviour_script.hpp"
#include "component.hpp"

void BehaviourScript::OnStart() {
    hasStarted = true;
}
void BehaviourScript::OnUpdate() {}
void BehaviourScript::OnTriggerEnter2D(const Collider &collider) {}
void BehaviourScript::OnTriggerExit2D(const Collider &collider) {}
void BehaviourScript::OnTriggerStay2D(const Collider &collider) {}
bool BehaviourScript::HasStarted() const { return hasStarted; }
