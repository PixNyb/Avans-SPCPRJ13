/**
 * @file particles.hpp
 * @author Martijn Vermeer
 * @brief This file contains the Particles class definition.
 * @version 0.1
 * @date 2023-20-12
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_PARTICLE_HPP
#define DEFUNBOBENGINE_PARTICLE_HPP

#include "behaviour_script.hpp"
#include "color.hpp"
#include "component.hpp"
#include "particle_type.hpp"
#include "point.hpp"
#include "texture.hpp"

/**
 * @struct Particle
 * @brief Represents a particle in the game engine.
 *
 * This structure defines the properties of a particle. Particles are used in particle systems to
 * simulate various visual effects.
 */
struct Particle
{
    Point position;        ///< The position of the particle.
    Point velocity;        ///< The velocity of the particle.
    float defaultLifetime; ///< The default lifetime of the particle.
    float lifetime;        ///< The remaining lifetime of the particle.
    Color color;           ///< The color of the particle.
    bool isAlive;          ///< Flag indicating whether the particle is alive.
    ParticleType type;     ///< The type of the particle.
    int size;              ///< The size of the particle.
    Point angle;           ///< The angle of the particle.

    /**
     * @brief Default constructor for Particle.
     *
     * Initializes the particle with default values.
     */
    Particle()
        : position({0, 0}), velocity({0, 0}), lifetime(0), size(0), angle({0, 0}),
          color(1.0f, 1.0f, 1.0f, 255), isAlive(false), type(ParticleType::Confetti)
    {
    }

    /**
     * @brief Updates the particle's position and lifetime.
     *
     * If the particle is alive, its position is updated based on velocity, and its lifetime
     * is decreased. If the lifetime drops to or below zero, the particle is marked as not alive.
     *
     * @param deltaTime The time elapsed since the last update.
     */
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

/**
 * @class Particles
 * @brief Manages a collection of particles in the game engine.
 *
 * This class extends BehaviourScript and represents a particle system. The particle system can emit
 * particles with specified properties.
 */
class Particles : public BehaviourScript
{
  private:
    std::vector<Particle> particles;  ///< Collection of particles in the system.
    Point emitterPosition;            ///< The position of the particle emitter.
    Point offset;                     ///< Offset applied to emitted particles.
    std::weak_ptr<GameObject> parent; ///< Weak pointer to the parent GameObject.
    ParticleType type;                ///< The type of particles in the system.

  public:
    /**
     * @brief Constructs a Particles object.
     *
     * Initializes the particle system with a reference to its parent GameObject.
     *
     * @param parent Weak pointer to the parent GameObject.
     */
    Particles(std::weak_ptr<GameObject> parent);

    /**
     * @brief Updates the particle system on each frame.
     *
     * This method is called on each frame update and is responsible for updating
     * various properties of the particles in the system.
     */
    void OnUpdate() override;

    /**
     * @brief Sets the position of the particle emitter.
     *
     * @param position The new position of the particle emitter.
     */
    void SetEmitterPosition(const Point &position);

    /**
     * @brief Gets the position of the particle emitter.
     *
     * @return The position of the particle emitter.
     */
    Point GetEmitterPosition() const;

    /**
     * @brief Adds particles to the system with specified properties.
     *
     * @param count The number of particles to add.
     * @param lifetime The lifetime of the particles.
     * @param offset The offset applied to emitted particles.
     * @param size The size of the particles.
     * @param angle The angle of the particles.
     * @param color The color of the particles.
     * @param particleType The type of particles to add.
     */
    void AddParticles(const int count, float lifetime, const Point &offset, const int size,
                      const Point &angle, const Color &color, const ParticleType &particleType);

    /**
     * @brief Gets the type of particles in the system.
     *
     * @return The type of particles.
     */
    ParticleType GetParticleType() const { return type; }

    /**
     * @brief Gets a const reference to the collection of particles.
     *
     * @return A const reference to the vector of particles.
     */
    const std::vector<Particle> &GetParticles() const { return particles; }

    /**
     * @brief Resets the properties of a particle to default values.
     *
     * @param particle The particle to reset.
     */
    void ResetParticle(Particle &particle);

    /**
     * @brief Creates a clone of the Particles component.
     *
     * @param parent Weak pointer to the new parent GameObject of the cloned component.
     * @return A shared pointer to the cloned Particles component.
     */
    std::shared_ptr<Component> Clone(std::weak_ptr<GameObject> parent) override;
};

#endif // DEFUNBOBENGINE_PARTICLE_HPP
