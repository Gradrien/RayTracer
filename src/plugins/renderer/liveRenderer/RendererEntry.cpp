/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** RendererEntry
*/

#include "IRenderer.hpp"
#include "Renderer.hpp"
#include <memory>

extern "C" {
std::unique_ptr<RayTracer::IRenderer> entryPoint()
{
    return (std::make_unique<RayTracer::LiveRenderer>());
}
}
