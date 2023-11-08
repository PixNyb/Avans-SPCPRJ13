/// @file

#ifndef AVANS_SPCPRJ13_TRANSFORM_H
#define AVANS_SPCPRJ13_TRANSFORM_H

#include "point.hpp"

/**
 * @brief Instances of this class represent specific 2D transformations.
 */
struct Transform {
    Point position; // Translation (shift)
    double rotation; // Rotation, in radians
    double scale; // Multiplication factor
};

#endif // AVANS_SPCPRJ13_TRANSFORM_H
