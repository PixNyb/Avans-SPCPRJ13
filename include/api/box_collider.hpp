/// @file

#ifndef AVANS_SPCPRJ13_BOXCOLLIDER_H
#define AVANS_SPCPRJ13_BOXCOLLIDER_H

#include "collider.hpp"
/**
 * @brief A collider which represents a rectangular collision area.
 */
class BoxCollider : public Collider
{
  public:
    /**
     * @brief The collider's width
     * @return The current width
     */
    double Width() const { return width; }

    /**
     * @brief The collider's width
     * @param newWidth The desired width
     */
    void Width(double newWidth) { width = newWidth; }

    /**
     * @brief The collider's height
     * @return The current height
     */
    double Height() const { return height; }

    /**
     * @brief The collider's height
     * @param newHeight The desired height
     */
    void Height(double newHeight) { height = newHeight; }

  private:
    double width;
    double height;
};

#endif // AVANS_SPCPRJ13_BOXCOLLIDER_H
