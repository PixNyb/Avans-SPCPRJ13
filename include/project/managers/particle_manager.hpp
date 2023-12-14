#ifndef DEFUNBOBENGINE_PARTICLE_MANAGER_HPP
#define DEFUNBOBENGINE_PARTICLE_MANAGER_HPP

#include "point.hpp"
#include "sprite.hpp"
#include "texture.hpp"
#include <SDL.h>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

class ParticleManager
{
  private:
    struct Particle
    {
        Point position;
        Point velocity;
        std::chrono::milliseconds lifetime;
        Texture texture;

        Particle()
            : position(0.0, 0.0), velocity(0.0, 0.0), lifetime(std::chrono::milliseconds(0)),
              texture("")
        {
        }
    };

    void ResetParticles(std::size_t index);

    std::vector<Particle> particles;
    std::vector<Sprite> sprites;
    std::vector<Point> vertices;
    std::vector<std::uint8_t> alphas;
    std::chrono::milliseconds lifeTime;
    Point emitter;
    bool useSprites;
    int amountOfParticles;

  public:
    ParticleManager(int amountOfParticles, const Texture &texture, bool useSprites);
    void SetEmitter(Point position);
    void Update(std::chrono::milliseconds elapsed);
    void Draw(SDL_Renderer *renderer);
};

#endif // DEFUNBOBENGINE_PARTICLE_MANAGER_HPP
