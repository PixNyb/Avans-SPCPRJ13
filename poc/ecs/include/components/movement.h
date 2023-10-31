#pragma once

#include "position2D.h"

struct MovementComponent {
    Position2D acceleration;
    Position2D velocity;
    Position2D max_velocity;
};