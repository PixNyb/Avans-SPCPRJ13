#include "particle.hpp"

Particle::Particle()
    : position(0.0, 0.0), velocity(0.0, 0.0), lifetime(0.5f), texture("")
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

bool Particle::IsAlive() const
{
    return lifetime > 0;
}
