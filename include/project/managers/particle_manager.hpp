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

#include "particles.hpp"
#include "sprite.hpp"
#include <chrono>
#include <memory>
#include <vector>

class ParticleManager {
private:
    std::vector<Particles> allParticles;

public:
    void Update();  // Update all Particles instances

    void AddParticles(const Particles& particles);  // Add new Particles instance

    const std::vector<Particles>& GetAllParticles() const;
};

#endif // DEFUNBOBENGINE_PARTICLE_MANAGER_HPP

