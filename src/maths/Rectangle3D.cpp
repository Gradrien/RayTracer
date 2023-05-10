/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

namespace Math {
Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side)
    : origin(origin)
    , bottom_side(bottom_side)
    , left_side(left_side)
{
}
}
