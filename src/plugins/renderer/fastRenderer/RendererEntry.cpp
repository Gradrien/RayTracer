/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RendererEntry
*/

#include <memory>
#include "IRenderer.hpp"
#include "Renderer.hpp"

extern "C"
{
std::unique_ptr<RayTracer::IRenderer> entryPoint()
{
    return (std::make_unique<RayTracer::FastRenderer>());
}
}
