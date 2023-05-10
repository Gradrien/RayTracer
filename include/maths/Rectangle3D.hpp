/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

/**
 * @namespace Math
 * @brief Namespace for the math functions
 */
namespace Math {
/**
 * @class Rectangle3D
 * @brief Class for the 3D rectangle
 */
class Rectangle3D {
public:
  Rectangle3D() = default;
  /**
   * @brief Constructs a new 3D rectangle with the given origin, bottom side
   * vector, and left side vector.
   *
   * @param origin The origin point of the rectangle.
   * @param bottom_side A vector representing the length and direction of the
   * bottom side of the rectangle.
   * @param left_side A vector representing the length and direction of the left
   * side of the rectangle.
   */
  Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side,
              Math::Vector3D left_side);
  ~Rectangle3D() = default;
  Math::Point3D origin;
  Math::Vector3D
      bottom_side; //* The vector from the bottom-left corner of the rectangle
                   // to the bottom-right corner of the rectangle
  Math::Vector3D left_side; //* The vector from the bottom-left corner of the
                            // rectangle to the top-left corner of the rectangle
};
} // namespace Math

#endif /* !RECTANGLE3D_HPP_ */
