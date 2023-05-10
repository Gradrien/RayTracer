/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Ray
*/

#include "Ray.hpp"
#include <cmath>
namespace RayTracer {
Ray::Ray(Math::Point3D origin, Math::Vector3D direction)
    : origin(origin)
    , direction(direction)
{
}

void Ray::rotateRay(double x, double y, double z)
{
    this->direction.rotateX(x);
    this->direction.rotateY(y);
    this->direction.rotateZ(z);
    this->origin.rotateX(x);
    this->origin.rotateY(y);
    this->origin.rotateZ(z);
}
}
