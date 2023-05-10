/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Encoder Entry
*/

#include <memory>
#include "IEncoder.hpp"
#include "Encoder.hpp"

extern "C"
{
std::unique_ptr<RayTracer::IEncoder> entryPoint()
{
    return (std::make_unique<RayTracer::SfmlEncoder>());
}
}
