#include "particle_manager.hpp"

void ParticleManager::Update() {
    for (auto& particles : allParticles) {
        particles.OnUpdate();
    }
}

void ParticleManager::AddParticles(const Particles& particles) {
    allParticles.push_back(particles);
    // Additional setup if required
}


const std::vector<Particles> &ParticleManager::GetAllParticles() const {
    return allParticles;
}
