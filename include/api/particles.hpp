#ifndef DEFUNBOBENGINE_PARTICLE_HPP
#define DEFUNBOBENGINE_PARTICLE_HPP

#include "behaviour_script.hpp"
#include "color.hpp"
#include "component.hpp"
#include "particle_type.hpp"
#include "point.hpp"
#include "texture.hpp"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Particle
{
    Point position;
    Point velocity;
    float defaultLifetime;
    float lifetime;
    Color color;
    bool isAlive;
    ParticleType type;

    Particle()
        : position({0, 0}), velocity({0, 0}), lifetime(0), color(1.0f, 1.0f, 1.0f, 255),
          isAlive(false), type(ParticleType::Confetti)
    {
    }

    void Update(float deltaTime)
    {
        if (isAlive)
        {
            position += velocity * deltaTime;
            lifetime -= deltaTime;
            if (lifetime <= 0)
            {
                isAlive = false;
            }
        }
    }
};

class Particles : public BehaviourScript
{
  private:
    std::vector<Particle> particles;
    Point emitterPosition;

  public:
    Particles(int count, float lifetime, const Point &initialPosition, const Color &color,
              const ParticleType &particleType);

    void OnUpdate() override;
    void SetEmitterPosition(const Point &position);

    const std::vector<Particle> &GetParticles() const { return particles; }

    void ResetParticle(Particle &particle);

    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;
};

#endif // DEFUNBOBENGINE_PARTICLE_HPP
