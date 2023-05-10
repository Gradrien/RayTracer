/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color
*/

#include "Color.hpp"

namespace RayTracer {
Color::Color(double r, double g, double b)
    : r { r }
    , g { g }
    , b { b }
{
}
double Color::getRIntensity() const { return this->r / 255; }

double Color::getGIntensity() const { return this->g / 255; }

double Color::getBIntensity() const { return this->b / 255; }

Color Color::operator+(const Color& color)
{
    Color result(this->r + color.r, this->g + color.g, this->b + color.b);
    return result;
}

double Color::getR() const { return (this->r < 255 ? this->r : 255); }

double Color::getG() const { return (this->g < 255 ? this->g : 255); }

double Color::getB() const { return (this->b < 255 ? this->b : 255); }

}
