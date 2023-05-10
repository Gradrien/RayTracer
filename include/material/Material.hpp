/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Material
*/

#ifndef RAYTRACER_MATERIAL_HPP
#define RAYTRACER_MATERIAL_HPP

#include "Color.hpp"

/**
 * @namespace RayTracer
 * @brief Namespace for the raytracer
 */
namespace RayTracer {
/**
  @brief Material class representing the properties of a surface of an object.
  @class Material
**/
class Material {
public:
  Material() = default;
  ~Material() = default;
  /**
   * @brief Construct a new Material object
   *
   * @param reflect the reflection coefficient of the material
   * @param specular the specular exponent of the material
   * @param color the color of the material
   * @param transparency the transparency of the material
   **/
  Material(double reflect, int specular, Color color, double transparency);
  /**
   * @brief Get the color of the material
   *
   * @return the color of the material
   */
  Color getColor() const;
  /**
   * @brief Set the color of the material
   *
   * @param r the red component of the color
   * @param g the green component of the color
   * @param b the blue component of the color
   */
  void setColor(double r, double g, double b);
  /**
   * @brief Get the specular exponent of the material
   *
   * @return the specular exponent of the material
   */
  int getSpecular() const;
  /**
   * @brief Set the specular exponent of the material
   *
   * @param spec the specular exponent to be set
   */
  void setSpecular(int spec);
  /**
   * @brief Get the reflection coefficient of the material
   *
   * @return the reflection coefficient of the material
   */
  double getReflective() const;
  /**
   * @brief Set the reflection coefficient of the material
   *
   * @param reflect the reflection coefficient to be set
   */
  void setReflective(double reflect);
  /**
   * @brief Set the transparency of the material
   *
   * @param transparency the transparency to be set
   */
  void setTransparency(double transparency);
  /**
   * @brief Get the transparency of the material
   *
   * @return the transparency of the material
   */
  double getTransparency();

private:
  double reflective_{0};
  int specular_{-1};
  Color color_{0, 0, 0};
  double transparency_{0};
};
} // namespace RayTracer

#endif // RAYTRACER_MATERIAL_HPP
