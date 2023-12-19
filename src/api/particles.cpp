#include "particles.hpp"
#include "engine.hpp"
#include "memory"
#include "particle_manager.hpp"
#include "time.hpp"

Particles::Particles(int count, float lifetime, const Point &initialPosition, const Color &color,
                     const ParticleType &particleType)
    : emitterPosition(initialPosition)
{

    particles.resize(count);
    for (auto &particle : particles)
    {
        particle.position = initialPosition;
        particle.defaultLifetime = lifetime;
        particle.lifetime = lifetime;
        particle.isAlive = true;
        particle.color = color;
        particle.type = particleType;
    }
}

void Particles::OnUpdate()
{
    float deltaTime = Time::GetDeltaTime();
    for (auto &particle : particles)
    {
        if (particle.isAlive)
        {
            switch (particle.type)
            {
            case ParticleType::Confetti:
                particle.position += particle.velocity * deltaTime;
                particle.lifetime -= deltaTime;
                break;
            case ParticleType::Rain:
                particle.position.y += particle.velocity.y * deltaTime;
                particle.lifetime -= deltaTime;
                break;
            }

            if (particle.lifetime <= 0)
            {
                // Reset the particle to start over again
                ResetParticle(particle);
            }
        }
    }
}

void Particles::SetEmitterPosition(const Point &position) { emitterPosition = position; }

std::shared_ptr<Component> Particles::Clone(std::weak_ptr<GameObject> parent)
{
    return std::make_shared<Particles>(*this);
}

void Particles::ResetParticle(Particle &particle)
{
    particle.lifetime = particle.defaultLifetime;

    switch (particle.type)
    {
    case ParticleType::Confetti:
        particle.position = emitterPosition;
        particle.velocity = Point{static_cast<float>(rand() % 10 - 5),
                                  static_cast<float>(rand() % 10 - 5)}; // Random velocity
        break;
    case ParticleType::Rain:
        particle.position =
            emitterPosition +
            Point{static_cast<float>(rand() % 1500),
                  static_cast<float>(rand() % 800 - 100)}; // Reset position to emitter's position
        particle.velocity = Point{static_cast<float>(rand() % 20 + 10),
                                  static_cast<float>(rand() % 20 + 10)}; // Random velocity
        break;
    }

    particle.isAlive = true; // Mark as alive
}
