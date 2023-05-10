/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ParseLight
*/

#include "Parser.hpp"

namespace RayTracer {
std::vector<std::unique_ptr<RayTracer::ILight>>& Parser::getLights()
{
    return lights_;
}
}
