#include "particles.hpp"
#include "time.hpp"
#include "engine.hpp"
#include "particle_manager.hpp"
#include "memory"

Particles::Particles(int count, float lifetime, const Point& initialPosition)
        : emitterPosition(initialPosition) {

    particles.resize(count);
    for (auto& particle : particles) {
        particle.position = initialPosition;
        particle.lifetime = lifetime;
        particle.isAlive = true;
        particle.color = Color(255.0f, 0.0f, 0.0f, 255);
        particle.velocity = Point{static_cast<float>(rand() % 10 - 5), static_cast<float>(rand() % 10 - 5)};
    }
}

void Particles::InitializeParticles(float lifetime, const Point& initialPosition) {
    for (auto& particle : particles) {
        particle.position = initialPosition;
        particle.lifetime = lifetime;
        particle.isAlive = true;
        particle.color = Color(1.0f, 1.0f, 1.0f, 255);
    }
}


void Particles::OnUpdate() {
    float deltaTime = Time::GetDeltaTime();
    for (auto& particle : particles) {
        if (particle.isAlive) {
            particle.position += particle.velocity * deltaTime;
            particle.lifetime -= deltaTime;

            if (particle.lifetime <= 0) {
                // Reset the particle to start over again
                ResetParticle(particle);
            }
        }
    }
}


void Particles::SetEmitterPosition(const Point& position) {
    emitterPosition = position;
}

std::shared_ptr<Component> Particles::Clone(std::weak_ptr<GameObject> parent) {
    return std::make_shared<Particles>(*this);
}

void Particles::ResetParticle(Particle& particle) {
    particle.position = emitterPosition; // Reset position to emitter's position
    particle.velocity = Point{static_cast<float>(rand() % 10 - 5), static_cast<float>(rand() % 10 - 5)}; // Random velocity
    particle.lifetime = 55.0f;
    particle.isAlive = true; // Mark as alive
}

