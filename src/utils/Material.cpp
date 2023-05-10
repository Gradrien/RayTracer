/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Material
*/

#include "Material.hpp"

RayTracer::Material::Material(double reflect, int specular, Color color, double transparency) : reflective_{reflect}, specular_{specular}, color_{color}, transparency_{transparency}
{
}

RayTracer::Color RayTracer::Material::getColor() const
{
    return this->color_;
}

void RayTracer::Material::setColor(double r, double g, double b)
{
    this->color_ = Color{r, g, b};
}

int RayTracer::Material::getSpecular() const
{
    return this->specular_;
}

void RayTracer::Material::setSpecular(int spec)
{
    this->specular_ = spec;
}

double RayTracer::Material::getReflective() const
{
    return this->reflective_;
}

void RayTracer::Material::setReflective(double reflect)
{
    this->reflective_ = reflect;
}

void RayTracer::Material::setTransparency(double transparency)
{
    this->transparency_ = transparency;
}

double RayTracer::Material::getTransparency()
{
    return this->transparency_;
}
