#ifndef DEFUNBOBENGINE_PARTICLE_MANAGER_HPP
#define DEFUNBOBENGINE_PARTICLE_MANAGER_HPP

#include "particle.hpp"
#include "sprite.hpp"
#include <chrono>
#include <memory>
#include <vector>

class ParticleManager
{
  private:
    void ResetParticles(std::size_t index);

    std::vector<std::unique_ptr<Particle>> particles;
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
    void Draw();
};

#endif // DEFUNBOBENGINE_PARTICLE_MANAGER_HPP
