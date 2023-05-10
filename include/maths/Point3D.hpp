/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "Vector3D.hpp"
#include <iostream>

/**
 * @namespace Math
 * @brief Namespace for the math functions
 */
namespace Math {
/**
 * @class Point3D
 * @brief Class for the 3D point
 */
class Point3D {
  public:
    Point3D() = default;
    /**
     * @brief Constructs a point with the given x, y, and z coordinates.
     *
     * @param x The x coordinate of the point.
     * @param y The y coordinate of the point.
     * @param z The z coordinate of the point.
     */
    Point3D(double x, double y, double z);
    /**
     * @brief Copy constructor, constructs a new point by copying the
     * coordinates of the given point.
     *
     * @param point The point to copy.
     */
    Point3D(Point3D&) = default;
    /**
     * @brief Move constructor, constructs a new point by moving the coordinates
     * of the given point.
     *
     * @param point The point to move.
     */
    Point3D(Point3D&&) = default;
    ~Point3D() = default;
    /**
     * @brief Copy assignment operator, assigns the coordinates of the given
     * point to this point.
     *
     * @param point The point to copy.
     * @return A reference to this point.
     */
    Point3D& operator=(const Point3D&) = default;
    /**
     * @brief Move assignment operator, moves the coordinates of the given point
     * to this point.
     *
     * @param point The point to move.
     * @return A reference to this point.
     */
    Point3D& operator=(Point3D&&) = default;
    /**
     * @brief Adds a vector to this point and returns the result as a new point.
     *
     * @param vect The vector to add.
     * @return The resulting point after adding the vector.
     */
    Point3D operator+(const Vector3D&);
    /**
     * @brief Rotate the point on the x axis
     *
     * @param x The x angle in radian
     */
    void rotateX(double x);
    /**
     * @brief Rotate the point on the y axis
     *
     * @param y The y angle in radian
     */
    void rotateY(double y);
    /**
     * @brief Rotate the point on the z axis
     *
     * @param z The z angle in radian
     */
    void rotateZ(double z);

    double x = 0;
    double y = 0;
    double z = 0;
};

/**
 * @brief Outputs a human-readable representation of the given point to the
 * given output stream.
 *
 * @param os The output stream to write to.
 * @param vect The point to output.
 * @return The output stream after writing the point.
 */
std::ostream& operator<<(std::ostream& os, const Point3D& vect);

} // namespace Math

#endif /* !POINT3D_HPP_ */
