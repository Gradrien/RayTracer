/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {
Math::Vector3D Camera::canvasToViewport(double u, double v)
{
    return { (u * this->screen.bottom_side.length() / this->imageSize_.width),
        (v * this->screen.left_side.length() / this->imageSize_.height),
        this->screen.origin.z };
}
void Camera::setBackgroundColor(Color color) { this->backgroundColor_ = color; }

Color Camera::getBackgroundColor() const { return this->backgroundColor_; }

}
