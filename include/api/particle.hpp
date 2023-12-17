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

struct Particle : BehaviourScript
{
    Particle();

    Point position;
    Point velocity;
    std::chrono::milliseconds lifetime;
    Texture texture;
    std::uint8_t color;

    void Update();

    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent);
};

#endif // DEFUNBOBENGINE_PARTICLE_HPP
