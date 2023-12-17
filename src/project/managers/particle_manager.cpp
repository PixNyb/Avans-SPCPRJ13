#include "particle_manager.hpp"

ParticleManager::ParticleManager(int amountOfParticles, const Texture &texture,
                                 const bool useSprites)
    : amountOfParticles(amountOfParticles), lifeTime(std::chrono::seconds(5)), emitter({0.0, 0.0}),
      useSprites(useSprites)
{
    particles.resize(amountOfParticles);
    sprites.resize(amountOfParticles);

    for (std::size_t i = 0; i < amountOfParticles; ++i)
    {
        particles[i] = std::make_unique<Particle>();
        particles[i]->texture = texture;
        ResetParticles(i);
        sprites[i].SetSprite(texture.getFilePath());
    }
}

void ParticleManager::SetEmitter(Point position) { emitter = position; }

void ParticleManager::Update(std::chrono::milliseconds elapsed)
{
    for (std::size_t i = 0; i < amountOfParticles; ++i)
    {
        Particle &particle = *particles[i];
        particle.lifetime -= elapsed;

        if (particle.lifetime <= std::chrono::milliseconds::zero())
        {
            ResetParticles(i);
        }

        particle.position += particle.velocity * (static_cast<double>(elapsed.count()) / 1000.0);
        double ratio = static_cast<double>(particle.lifetime.count()) / lifeTime.count();
        particle.color = static_cast<std::uint8_t>(ratio * 255);
    }
}

void ParticleManager::ResetParticles(std::size_t index)
{
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;

    particles[index]->velocity = Point{std::cos(angle) * speed, std::sin(angle) * speed};
    particles[index]->lifetime = std::chrono::milliseconds{(std::rand() % 2000) + 1000};
    particles[index]->position = emitter;
}