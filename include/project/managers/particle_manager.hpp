/**
 * @file particle_manager.hpp
 * @author Martijn Vermeer
 * @brief This file contains the ParticleManager class.
 * @version 0.1
 * @date 2023-12-18
 *
 *
 *
 * Copyright Copyright (c) 2023
 */

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
    float lifeTime;
    Point emitter;
    bool useSprites;
    int amountOfParticles;

public:
    ParticleManager();
    ParticleManager(int amountOfParticles, bool useSprites);
    void SetEmitter(Point position);
    void Update(double elapsed);
    void SetTexture(const Texture& texture);
    void SetLifeTime(float deltaTime) { this->lifeTime = deltaTime; }
    void SetAmountOfParticles(int amountOfParticles);

    std::vector<Point> GetVertices() const;
    void Draw();
    const std::vector<std::unique_ptr<Particle>>& GetParticles() const { return particles; }
};

#endif // DEFUNBOBENGINE_PARTICLE_MANAGER_HPP

