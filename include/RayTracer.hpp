/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RayTracer
*/

#ifndef RAYTRACER_RAYTRACER_HPP
#define RAYTRACER_RAYTRACER_HPP
#include "IPrimitives.hpp"

/**
 * @namespace RayTracer
 * @brief Namespace for the raytracer
 */
namespace RayTracer {
/**
 * @struct intersection
 * @brief Struct for the intersection
 */
struct intersection {
    IPrimitives& closestPrim;
    double closestT;
};
} // namespace RayTracer

#endif // RAYTRACER_RAYTRACER_HPP
