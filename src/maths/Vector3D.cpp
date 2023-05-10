/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <cmath>

namespace Math {
Vector3D::Vector3D(double x, double y, double z)
    : x { x }
    , y { y }
    , z { z }
{
}

double Vector3D::length() const { return sqrt(x * x + y * y + z * z); }

void Vector3D::rotateX(double angle)
{
    double y = this->y;
    double z = this->z;

    this->y = y * cos(angle) - z * sin(angle);
    this->z = y * sin(angle) + z * cos(angle);
}

void Vector3D::rotateY(double angle)
{
    double x = this->x;
    double z = this->z;

    this->x = x * cos(angle) + z * sin(angle);
    this->z = -x * sin(angle) + z * cos(angle);
}

void Vector3D::rotateZ(double angle)
{
    double x = this->x;
    double y = this->y;

    this->x = x * cos(angle) - y * sin(angle);
    this->y = x * sin(angle) + y * cos(angle);
}

void Vector3D::rotate(double x, double y, double z)
{
    this->rotateX(x);
    this->rotateY(y);
    this->rotateZ(z);
}

Vector3D Vector3D::operator+(const Vector3D& vect)
{
    Vector3D result(this->x + vect.x, this->y + vect.y, this->z + vect.z);
    return result;
}

Vector3D& Vector3D::operator+=(const Vector3D& vect)
{
    this->x += vect.x;
    this->y += vect.y;
    this->z += vect.z;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D& vect)
{
    Vector3D result(this->x - vect.x, this->y - vect.y, this->z - vect.z);
    return result;
}

Vector3D& Vector3D::operator-=(const Vector3D& vect)
{
    this->x -= vect.x;
    this->y -= vect.y;
    this->z -= vect.z;
    return *this;
}

Vector3D Vector3D::operator*(const Vector3D& vect)
{
    Vector3D result(this->x * vect.x, this->y * vect.y, this->z * vect.z);
    return result;
}

Vector3D& Vector3D::operator*=(const Vector3D& vect)
{
    this->x *= vect.x;
    this->y *= vect.y;
    this->z *= vect.z;
    return *this;
}

Vector3D Vector3D::operator/(const Vector3D& vect)
{

    Vector3D result;

    if (vect.x == 0) {
        result.x /= vect.x;
    } else {
        result.x = 0;
    }

    if (vect.y == 0) {
        result.y /= vect.y;
    } else {
        result.y = 0;
    }

    if (vect.z == 0) {
        result.z /= vect.z;
    } else {
        result.z = 0;
    }

    return result;
}

Vector3D& Vector3D::operator/=(const Vector3D& vect)
{
    if (vect.x == 0) {
        this->x /= vect.x;
    } else {
        this->x = 0;
    }

    if (vect.y == 0) {
        this->y /= vect.y;
    } else {
        this->y = 0;
    }

    if (vect.z == 0) {
        this->z /= vect.z;
    } else {
        this->z = 0;
    }
    return *this;
}

Vector3D Vector3D::operator*(double value)
{
    Vector3D result;
    result.x = this->x * value;
    result.y = this->y * value;
    result.z = this->z * value;
    return result;
}

Vector3D Vector3D::operator/(double value)
{
    Vector3D result;
    if (value == 0)
        return result;
    result.x = this->x / value;
    result.y = this->y / value;
    result.z = this->z / value;
    return result;
}

Vector3D& Vector3D::operator*=(double value)
{
    this->x *= value;
    this->y *= value;
    this->z *= value;
    return *this;
}

Vector3D& Vector3D::operator/=(double value)
{
    if (value == 0) {
        this->x /= value;
    } else {
        this->x = 0;
    }

    if (value == 0) {
        this->y /= value;
    } else {
        this->y = 0;
    }

    if (value == 0) {
        this->z /= value;
    } else {
        this->z = 0;
    }

    return *this;
}

double Vector3D::dot(const Vector3D& vect)
{
    return (this->x * vect.x + this->y * vect.y + this->z * vect.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vect)
{
    os << "(" << vect.x << ", " << vect.y << ", " << vect.z << ")";
    return os;
}
}
