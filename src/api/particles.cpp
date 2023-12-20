#include "particles.hpp"
#include "camera.hpp"
#include "engine.hpp"
#include "memory"
#include "scene_manager.hpp"
#include "time.hpp"

Particles::Particles(std::weak_ptr<GameObject> parent) { this->parent = parent; }

void Particles::AddParticles(const int count, float lifetime, const Point &offset, const int size,
                             const Point &angle, const Color &color,
                             const ParticleType &particleType)
{
    this->offset = offset;
    this->type = particleType;

    for (int i = 0; i < count; ++i)
    {
        Particle particle;
        particle.defaultLifetime = lifetime;
        particle.lifetime = lifetime;
        particle.isAlive = true;
        particle.color = color;
        particle.type = particleType;
        particle.angle = angle;
        particle.size = size;

        particles.push_back(particle);
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

void Particles::SetEmitterPosition(const Point &position) { emitterPosition = position + offset; }

std::shared_ptr<Component> Particles::Clone(std::weak_ptr<GameObject> parent)
{
    auto clone = std::make_shared<Particles>(*this);
    clone->parent = parent;
    return clone;
}

void Particles::ResetParticle(Particle &particle)
{
    auto engine = Engine::GetInstance();
    auto sceneManager = engine->Get<SceneManager>();
    auto scene = sceneManager->GetScene().lock();
    auto camera = scene->GetCamera();

    particle.lifetime =
        static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * particle.defaultLifetime;

    switch (particle.type)
    {
    case ParticleType::Confetti:
        particle.position = emitterPosition;
        particle.velocity =
            Point{static_cast<float>(rand() % 100 - 50), static_cast<float>(rand() % 100 - 50)};
        break;
    case ParticleType::Rain:
        particle.position =
            emitterPosition + Point{static_cast<float>(rand() % camera->GetAspectWidth()),
                                    static_cast<float>(rand() % camera->GetAspectHeight())};
        particle.velocity =
            Point{static_cast<float>(rand() % 10 + 5), static_cast<float>(rand() % 10 + 5)};
        break;
    }

    particle.isAlive = true; // Mark as alive
}
