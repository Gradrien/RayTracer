/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RendererEntry
*/

#include <memory>
#include "IPrimitives.hpp"
#include "Cone.hpp"

extern "C"
{
std::unique_ptr<RayTracer::IPrimitives> entryPoint()
{
    return (std::make_unique<RayTracer::Cone>());
}
}
