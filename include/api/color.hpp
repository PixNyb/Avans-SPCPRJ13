/**
 * @file color.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Color class for representing RGBA colors in the DefunBobEngine.
 * The Color class provides a representation of colors using the red, green, blue, and alpha (transparency)
 * components. It also includes predefined static instances of common colors for convenience.
 * Each color component is a double value ranging from 0 to 1.
 *
 * @copyright Copyright (c) 2023
 */


#ifndef DEFUNBOBENGINE_COLOR_H
#define DEFUNBOBENGINE_COLOR_H

/**
  * @class Color
  * @brief Represents a color using red, green, blue, and alpha (transparency) components.
  *
  * The Color class encapsulates colors in RGBA format. It includes methods to create colors
  * and static members representing common colors.
  */
class Color {
public:
    /**
     * @brief Constructor, accepting an rgb value and an alpha (transparency).
     * @param red The red component, 0 ≤ r ≤ 1.
     * @param green The green component, 0 ≤ g ≤ 1.
     * @param blue The blue component, 0 ≤ b ≤ 1.
     * @param alpha The transparency component, 0 ≤ alpha ≤ 1.
     */
    Color(double red, double green, double blue, double alpha);

    /**
     * @brief Returns the red component of the color.
     * @return The red component, 0 ≤ r ≤ 1.
     */
    double GetRed() const;

    /**
     * @brief Returns the green component of the color.
     * @return The green component, 0 ≤ g ≤ 1.
     */
    double GetGreen() const;

        /**
         * @brief Returns the blue component of the color.
         * @return The blue component, 0 ≤ b ≤ 1.
         */
    double GetBlue() const;

    /**
     * @brief Returns the alpha (transparency) component of the color.
     * @return The alpha component, 0 ≤ alpha ≤ 1.
     */
    double GetAlpha() const;

    /**
     * @brief One of the standard colors (read-only): white.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& white()   { return _white; }

    /**
     * @brief One of the standard colors (read-only): red.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& red()     { return _red; }

    /**
     * @brief One of the standard colors (read-only): green.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& green()   { return _green; }

    /**
     * @brief One of the standard colors (read-only): blue.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& blue()    { return _blue; }

    /**
     * @brief One of the standard colors (read-only): cyan.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& cyan()    { return _cyan; }

    /**
     * @brief One of the standard colors (read-only): magenta.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& magenta() { return _magenta; }

    /**
     * @brief One of the standard colors (read-only): yellow.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& yellow()  { return _yellow; }

    /**
     * @brief One of the standard colors (read-only): black.
     * @return A reference to a statically allocated Color instance.
     */
    static const Color& black()   { return _black; }
    // ... more standard colors here

private:
    double r;
    double g;
    double b;
    double a;

    static Color _white;
    static Color _red;
    static Color _green;
    static Color _blue;
    static Color _cyan;
    static Color _magenta;
    static Color _yellow;
    static Color _black;
    // ... more standard color here
};

#endif //DEFUNBOBENGINE_COLOR_H
