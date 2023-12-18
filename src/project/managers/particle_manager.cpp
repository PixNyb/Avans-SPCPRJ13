#include "particle_manager.hpp"

ParticleManager::ParticleManager() {}

// Constructor without Texture parameter
ParticleManager::ParticleManager(int amountOfParticles, bool useSprites)
        : amountOfParticles(amountOfParticles), lifeTime(0.5f), emitter({0.0, 0.0}),
          useSprites(useSprites)
{
    particles.resize(amountOfParticles);
    sprites.resize(amountOfParticles);

    for (std::size_t i = 0; i < amountOfParticles; ++i)
    {
        particles[i] = std::make_unique<Particle>();
        ResetParticles(i);
    }
}

void ParticleManager::SetTexture(const Texture& texture)
{
    for (auto& particle : particles)
    {
        particle->SetTexture(texture);
    }
    for (auto& sprite : sprites)
    {
        sprite.SetSprite(texture.getFilePath());
    }
}

void ParticleManager::SetEmitter(Point position) { emitter = position; }

void ParticleManager::Update(double deltaTimeSeconds)
{
    for (std::size_t i = 0; i < amountOfParticles; ++i)
    {
        Particle &particle = *particles[i];

        // Update lifetime
        float currentLifetime = particle.GetLifetime();
        currentLifetime -= static_cast<float>(deltaTimeSeconds);
        particle.SetLifetime(currentLifetime);

        // Check if the particle is still alive
        if (currentLifetime <= 0.0f)
        {
            ResetParticles(i);
            continue; // Move to the next particle
        }

        // Update position
        Point currentPosition = particle.GetPosition();
        Point currentVelocity = particle.GetVelocity();
        currentPosition += currentVelocity * static_cast<float>(deltaTimeSeconds);
        particle.SetPosition(currentPosition);

        // Update color based on remaining lifetime
        float ratio = currentLifetime / lifeTime;
        std::uint8_t newColor = static_cast<std::uint8_t>(ratio * 255);
        particle.SetColor(newColor);
    }
}

void ParticleManager::ResetParticles(std::size_t index)
{
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;

    Point newVelocity = Point{std::cos(angle) * speed, std::sin(angle) * speed};
    particles[index]->SetVelocity(newVelocity);

    float newLifetime = static_cast<float>((std::rand() % 2) + 1); // Random lifetime between 1 and 2 seconds
    particles[index]->SetLifetime(newLifetime);

    particles[index]->SetPosition(emitter);
}

void ParticleManager::SetAmountOfParticles(int amountOfParticles) {
    this->amountOfParticles = amountOfParticles;

    particles.resize(amountOfParticles);
    sprites.resize(amountOfParticles);

    for (std::size_t i = 0; i < amountOfParticles; ++i)
    {
        particles[i] = std::make_unique<Particle>();
        particles[i]->SetPosition(emitter);
        particles[i]->SetLifetime(lifeTime);
        ResetParticles(i);
    }
}


