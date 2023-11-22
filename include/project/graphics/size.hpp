/**
 * @file size.hpp
 * @author Robin Pijnappels
 * @brief Defines the Size struct.
 * @version 0.1
 * @date 2023-11-22
 *
 * The Size struct represents a width and height.
 * It is used for representing the size of a texture or window.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_SIZE_HPP
#define DEFUNBOBENGINE_SIZE_HPP

/**
 * @struct Size
 * @brief Represents a width and height.
 *
 * Size is a simple struct that represents a width and height.
 * It is used for representing the size of a texture or window.
 */
struct Size {
    int width; ///< The width.
    int height; ///< The height.

    /**
     * @brief Constructs a Size with default values.
     */
    Size() : width(0), height(0) {}

    /**
     * @brief Constructs a Size with the specified width and height.
     * @param w The width.
     * @param h The height.
     */
    Size(int w, int h) : width(w), height(h) {}

    /**
     * @brief Retrieves the width.
     * @return int width
     */
    [[nodiscard]] int getWidth() const { return width; }

    /**
    * @brief Retrieves the height.
    * @return int height
    */
    [[nodiscard]] int getHeight() const { return height; }
};

#endif //DEFUNBOBENGINE_SIZE_HPP
