/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color
*/

#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

namespace RayTracer {
class Color {
public:
  Color() = default;
  ~Color() = default;
  /**
   * @brief Constructs a Color object with the given RGB values.
   * @param r The red component of the color.
   * @param g The green component of the color.
   * @param b The blue component of the color.
   */
  Color(double r, double g, double b);
  /**
   * @brief Returns the intensity of the red component of the color.
   * @return A double representing the intensity of the red component.
   */
  double getRIntensity() const;
  /**
   * @brief Returns the intensity of the green component of the color.
   * @return A double representing the intensity of the green component.
   */
  double getGIntensity() const;
  /**
   * @brief Returns the intensity of the blue component of the color.
   * @return A double representing the intensity of the blue component.
   */
  double getBIntensity() const;
  /**
   * @brief Adds the given color to this color.
   * @param color The color to be added.
   * @return A Color object representing the sum of the two colors.
   */
  Color operator+(const Color &);

  double getR() const;
  double getG() const;
  double getB() const;

  double r;
  double g;
  double b;
};
} // namespace RayTracer

#endif // RAYTRACER_COLOR_HPP
