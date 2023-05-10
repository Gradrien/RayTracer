/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ParsePrimitive
*/

#include "Parser.hpp"

namespace RayTracer {

std::vector<std::unique_ptr<RayTracer::IPrimitives>>& Parser::getPrimitives()
{
    return primitives_;
}
}
