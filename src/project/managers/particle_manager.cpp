#include "particle_manager.hpp"
#include "iostream"

ParticleManager::ParticleManager(int amountOfParticles, const Texture &texture,
                                 const bool useSprites)
    : amountOfParticles(amountOfParticles), lifeTime(std::chrono::seconds(5)), emitter({0.0, 0.0}),
      useSprites(useSprites)
{
    particles.resize(amountOfParticles);
    alphas.resize(amountOfParticles);
    vertices.resize(amountOfParticles);
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
    alphas.clear();

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
        alphas.emplace_back(static_cast<std::uint8_t>(ratio * 255));
        vertices[i] = particle.position;
    }
}

// void ParticleManager::Draw(SDL_Renderer *renderer)
//{
//     for (std::size_t i = 0; i < vertices.size(); ++i)
//     {
//         SDL_SetRenderDrawColor(renderer, 255, 255, 255, alphas[i]);
//         SDL_RenderDrawPoint(renderer, static_cast<int>(vertices[i].x),
//                             static_cast<int>(vertices[i].y));
//     }
// }

void ParticleManager::ResetParticles(std::size_t index)
{
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;

    particles[index]->velocity = Point{std::cos(angle) * speed, std::sin(angle) * speed};
    particles[index]->lifetime = std::chrono::milliseconds{(std::rand() % 2000) + 1000};
    vertices[index] = emitter;
}