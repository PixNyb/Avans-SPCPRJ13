/// @file

#ifndef AVANS_SPCPRJ13_CIRCLECOLLIDER_H
#define AVANS_SPCPRJ13_CIRCLECOLLIDER_H

#include "collider.hpp"

/**
 * @brief A collider which represents a circular collision area.
 */
class CircleCollider : public Collider
{
  public:
    /**
     * @brief Get the collider's radius
     * @return The radius
     */
    double Radius() const { return radius; }

    /**
     * @brief Set the collider's radius
     * @param newRadius The desired radius
     */
    void Radius(double newRadius) { radius = newRadius; }

  private:
    double radius;
};

#endif // AVANS_SPCPRJ13_CIRCLECOLLIDER_H
