/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

/**
 * @namespace RayTracer
 * @brief Namespace for the raytracer
 */
namespace RayTracer {
/**
 * @class Ray
 * @brief Class for the ray
 */
class Ray {
public:
  Ray() = default;
  /**
   * @brief Constructs a new 3D ray with the given origin point and direction
   * vector.
   *
   * @param origin The origin point of the ray.
   * @param direction A vector representing the direction of the ray.
   */
  Ray(Math::Point3D, Math::Vector3D);
  /**
   * @brief Constructs a new 3D ray by copying or moving the contents of the
   * given ray.
   *
   * @param ray The ray to copy.
   */
  Ray(Ray &) = default;
  /**
   * @brief Constructs a new 3D ray by copying or moving the contents of the
   * given ray.
   *
   * @param ray The ray to move.
   */
  Ray(Ray &&) = default;
  /**
   * @brief Rotate the ray (origin and direction)
   *
   * @param x The x angle in radian
   * @param y The y angle in radian
   * @param z The z angle in radian
   */
  void rotateRay(double x, double y, double z);
  ~Ray() = default;
  Math::Point3D origin;
  Math::Vector3D direction;
};
} // namespace RayTracer

#endif /* !RAY_HPP_ */
