#ifndef DEFUNBOBENGINE_PARTICLE_HPP
#define DEFUNBOBENGINE_PARTICLE_HPP

#include "behaviour_script.hpp"
#include "component.hpp"
#include "point.hpp"
#include "texture.hpp"
#include "color.hpp"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Particle {
    Point position;
    Point velocity;
    float lifetime;
    Color color;
    bool isAlive;

    Particle() : position({0, 0}), velocity({0, 0}), lifetime(0), color(1.0f, 1.0f, 1.0f, 255), isAlive(false) {}

    void Reset() {
        isAlive = true;
    }

    void Update(float deltaTime) {
        if (isAlive) {
            position += velocity * deltaTime;
            lifetime -= deltaTime;
            if (lifetime <= 0) {
                isAlive = false;
            }
        }
    }
};

class Particles : public BehaviourScript {
private:
    std::vector<Particle> particles;
    Point emitterPosition;

public:
    Particles(int count, float lifetime, const Point& initialPosition);

    void OnUpdate() override;
    void SetEmitterPosition(const Point& position);
    void InitializeParticles(float lifetime, const Point& initialPosition);

    const std::vector<Particle>& GetParticles() const { return particles; }

    void Reset();

    void ResetParticle(Particle& particle);

    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;

};

#endif // DEFUNBOBENGINE_PARTICLE_HPP

