/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <iostream>

/**
 * @namespace Math
 * @brief Namespace for the math library
 */
namespace Math {
/****************************************************************
  @class Vector3D
  @brief Class representing a 3D vector.
  This class represents a vector in three dimensions and provides basic
mathematical operations for vector manipulation.
*****************************************************************/
class Vector3D {
public:
  Vector3D() = default;
  /****************************************************************
   * @brief  Vector3D
   * @note   constructor of the class
   * @param  x the x coordinate
   * @param  y the y coordinate
   * @param  z the z coordinate
   ****************************************************************/
  Vector3D(double x, double y, double z);
  /****************************************************************
   * @brief  Vector3D
   * @note   constructor of the class
   * @param  vect the vector
   ****************************************************************/
  Vector3D(Vector3D &) = default;
  /****************************************************************
   * @brief  Vector3D
   * @note   constructor of the class
   * @param  vect the vector
   ****************************************************************/
  Vector3D(Vector3D &&) = default;
  ~Vector3D() = default;
  /****************************************************************
   * @brief  length
   * @note   get the length of the vector
   * @return a double containing the length of the vector
   ****************************************************************/
  double length() const;

  /****************************************************************
   * @brief Copy assignment operator.
   * @param vector The vector whose values should be copied.
   * @return A reference to the current vector.
   ****************************************************************/
  Vector3D &operator=(const Vector3D &) = default;
  /****************************************************************
   * @brief Move assignment operator.
   * @param vector The vector whose values should be moved.
   * @return A reference to the current vector.
   ****************************************************************/
  Vector3D &operator=(Vector3D &&) = default;
  /**
   * @brief Addition operator for vectors.
   * @param vector The vector to add.
   * @return A new vector resulting from the addition of the two vectors.
   */
  Vector3D operator+(const Vector3D &);
  /**
   * @brief Addition operator for vectors with assignment.
   * @param vector The vector to add.
   * @return A reference to the current vector after adding the vector passed as
   * a parameter.
   */
  Vector3D &operator+=(const Vector3D &);
  /**
   * @brief Subtraction operator for vectors.
   * @param vector The vector to subtract.
   * @return A new vector resulting from the subtraction of the two vectors.
   */
  Vector3D operator-(const Vector3D &);
  /**
   * @brief Subtraction operator for vectors with assignment.
   * @param vector The vector to subtract.
   * @return A reference to the current vector after subtracting the vector
   * passed as a parameter.
   */
  Vector3D &operator-=(const Vector3D &);
  /**
   * @brief Multiplication operator for vectors.
   * @param vector The vector to multiply.
   * @return A new vector resulting from the multiplication of the two vectors.
   **/
  Vector3D operator*(const Vector3D &);
  /**
   * @brief Multiplication operator for vectors with assignment.
   * @param vector The vector to multiply.
   * @return A reference to the current vector after multiplying the vector
   *passed as a parameter.
   **/
  Vector3D &operator*=(const Vector3D &);
  /**
   * @brief Division operator for vectors.
   * @param vector The vector to divide.
   * @return A new vector resulting from the division of the two vectors.
   */
  Vector3D operator/(const Vector3D &);
  /**
   * @brief Division operator for vectors with assignment.
   * @param vector The vector to divide.
   * @return A reference to the current vector after dividing the vector passed
   * as a parameter.
   */
  Vector3D &operator/=(const Vector3D &);
  /**
   * @brief Multiplication operator for scalar values.
   * @param scalar The scalar value to multiply.
   * @return A new vector resulting from the multiplication of the vector by the
   *scalar.
   **/
  Vector3D operator*(double);
  /**
   * @brief Multiplication operator for scalar values with assignment.
   * @param scalar The scalar value to multiply.
   * @return A reference to the current vector after multiplying the vector by
   *the scalar value.
   **/
  Vector3D &operator*=(double);
  /**
   * @brief Division operator for scalar values.
   *
   * @param scalar The scalar value to divide.
   * @return A new vector resulting from the division of the vector by the
   *scalar.
   **/
  Vector3D operator/(double);
  /**
   * @brief Division operator for scalar values with assignment.
   *
   * @param scalar The scalar value to divide.
   * @return A reference to the current vector after dividing the vector by the
   * scalar value.
   */
  Vector3D &operator/=(double);
  /**
   * @brief Calculates the dot product of this vector and another vector.
   *
   * @param other The other vector to calculate the dot product with.
   * @return The dot product of the two vectors as a double value.
   **/
  double dot(const Vector3D &);
  /**
   * @brief Rotate the vector in the 3 directions
   *
   * @param x The x angle in radian
   * @param y The y angle in radian
   * @param z The z angle in radian
   **/
  void rotate(double x, double y, double z);
  /**
   * @brief Rotate the vector (origin and direction) on the x axis
   *
   * @param x The x angle in radian
   */
  void rotateX(double x);
  /**
   * @brief Rotate the vector (origin and direction) on the y axis
   *
   * @param y The y angle in radian
   */
  void rotateY(double y);
  /**
   * @brief Rotate the vector (origin and direction) on the z axis
   *
   * @param z The z angle in radian
   */
  void rotateZ(double z);

  double x = 0;
  double y = 0;
  double z = 0;
};

/**
 * @brief Calculates the cross product of two vectors.
 *
 * @param vector1 The first vector.
 * @param vector2 The second vector.
 * @return The cross product of the two vectors as a new vector.
 */
std::ostream &operator<<(std::ostream &os, const Vector3D &vect);

} // namespace Math

#endif /* !VECTOR3D_HPP_ */
