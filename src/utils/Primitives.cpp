/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitives
*/

#include "APrimitives.hpp"

RayTracer::Material RayTracer::APrimitives::getMaterial()
{
    return this->material_;
}

void RayTracer::APrimitives::setMaterial(RayTracer::Color color, double reflect, int specular, double transparency)
{
    this->material_.setColor(color.r, color.g, color.b);
    this->material_.setSpecular(specular);
    this->material_.setReflective(reflect);
    this->material_.setTransparency(transparency);
}
