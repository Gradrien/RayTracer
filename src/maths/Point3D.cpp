/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Point3D
*/

#include "Point3D.hpp"
#include <cmath>
namespace Math {
Point3D::Point3D(double x, double y, double z)
    : x { x }
    , y { y }
    , z { z }
{
}

void Point3D::rotateX(double angle)
{
    double y = this->y;
    double z = this->z;

    this->y = y * cos(angle) - z * sin(angle);
    this->z = y * sin(angle) + z * cos(angle);
}

void Point3D::rotateY(double angle)
{
    double x = this->x;
    double z = this->z;

    this->x = x * cos(angle) + z * sin(angle);
    this->z = -x * sin(angle) + z * cos(angle);
}

void Point3D::rotateZ(double angle)
{
    double x = this->x;
    double y = this->y;

    this->x = x * cos(angle) - y * sin(angle);
    this->y = x * sin(angle) + y * cos(angle);
}

std::ostream &operator<<(std::ostream &os, const Point3D &pt)
{
    os << "(" << pt.x << ", " << pt.y << ", " << pt.z << ")";
    return os;
}

Point3D Point3D::operator+(const Vector3D& vect)
{
    return Point3D(this->x + vect.x, this->y + vect.y, this->z + vect.z);
}


}
