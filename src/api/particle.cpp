#include "particle.hpp"

Particle::Particle()
    : position(0.0, 0.0), velocity(0.0, 0.0), lifetime(std::chrono::milliseconds(0)), texture("")
{
}

void Particle::Update()
{
    // todo
}

std::shared_ptr<Component> Particle::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Particle>(*this);
}
