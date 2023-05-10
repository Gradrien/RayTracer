/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Color.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "RayTracer.hpp"
#include "Rectangle3D.hpp"
#include "Size.hpp"
#define PI_RAD 3.14159265 / 180

namespace RayTracer {
class Camera {
  public:
    Camera() = default;
    ~Camera() = default;
    Math::Point3D origin { 0, 0, 0 };
    Math::Rectangle3D screen;
    Math::Vector3D rotation_;
    imageSize imageSize_ { 400, 400 };
    /**
        @brief Converts canvas coordinates to viewport coordinates.
        @param u The x coordinate of the canvas.
        @param v The y coordinate of the canvas.
        @return A Vector3D representing the converted viewport coordinates.
    **/
    Math::Vector3D canvasToViewport(double u, double v);
    /**
     * @brief Sets the background color of the scene.
     *
     * @param color The new background color to set.
     */
    void setBackgroundColor(Color color);
    /**
     * @brief Returns the background color of the scene.
     *
     * @return The background color of the scene.
     */
    Color getBackgroundColor() const;
    int reccursionDepth_ { 1 };

  private:
    Color backgroundColor_;
};
} // namespace RayTracer

#endif /* !CAMERA_HPP_ */
