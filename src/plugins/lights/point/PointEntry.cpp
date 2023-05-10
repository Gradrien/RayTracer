/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RendererEntry
*/

#include <memory>
#include "ILight.hpp"
#include "PointLight.hpp"

extern "C"
{
std::unique_ptr<RayTracer::ILight> entryPoint()
{
    return (std::make_unique<RayTracer::PointLight>());
}
}
