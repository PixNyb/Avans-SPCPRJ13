#ifndef DEFUNBOBENGINE_PARTICLE_HPP
#define DEFUNBOBENGINE_PARTICLE_HPP

#include "behaviour_script.hpp"
#include "component.hpp"
#include "point.hpp"
#include "texture.hpp"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Particle : public BehaviourScript
{
private:
    Point position;
    Point velocity;
    float lifetime;
    Texture texture;
    std::uint8_t color;

public:
    Particle();

    // Getter and setter methods
    const Point& GetPosition() const { return position; }
    void SetPosition(const Point& newPosition) { position = newPosition; }

    const Point& GetVelocity() const { return velocity; }
    void SetVelocity(const Point& newVelocity) { velocity = newVelocity; }

    float GetLifetime() const { return lifetime; }
    void SetLifetime(float  newLifetime) { lifetime = newLifetime; }

    const Texture& GetTexture() const { return texture; }
    void SetTexture(const Texture& newTexture) { texture = newTexture; }

    std::uint8_t GetColor() const { return color; }
    void SetColor(std::uint8_t newColor) { color = newColor; }

    bool IsAlive() const;

    void Update();

    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent);
};

#endif // DEFUNBOBENGINE_PARTICLE_HPP
