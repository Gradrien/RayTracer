/*
** EPITECH PROJECT, 2023
** BS RayTracer
** File description:
** sphere
*/

#include "Sphere.hpp"
#include <cmath>

namespace RayTracer {
Sphere::Sphere(double radius, Math::Point3D center)
    : radius_{radius},
    center_{center}
{
}

std::vector<double> Sphere::getIntersection(RayTracer::Ray ray)
{
    Math::Vector3D co;
    co.x = ray.origin.x - this->center_.x;
    co.y = ray.origin.y - this->center_.y;
    co.z = ray.origin.z - this->center_.z;

    double a = ray.direction.dot(ray.direction);
    double b = co.dot(ray.direction) * 2;
    double c = co.dot(co) - pow(this->radius_, 2);

    double delta = pow(b, 2) - (4 * a * c);

    if (delta < 0)
        return {};
    if (delta == 0)
        return { -b / (2 * a) };

    return { (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a) };
}

Math::Vector3D Sphere::getNormalVector(Math::Point3D point)
{
    Math::Vector3D normal;
    normal.x = point.x - this->center_.x;
    normal.y = point.y - this->center_.y;
    normal.z = point.z - this->center_.z;
    normal = normal / normal.length();
    return normal;
}

Math::Vector3D Sphere::getRotationVector() {
    return {0, 0, 0};
}

void Sphere::checkJsonExistence(
    const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument("Le champ JSON '" + field_name + "' n'existe pas.");
}

void Sphere::checkRangeValue(const json& scene, const std::string& field_name,
    const std::string& comparison_sign, double value)
{
    double fieldValue = scene[field_name];
    bool isValid = false;

    if (comparison_sign == ">") {
        isValid = (fieldValue > value);
    } else if (comparison_sign == ">=") {
        isValid = (fieldValue >= value);
    } else if (comparison_sign == "<") {
        isValid = (fieldValue < value);
    } else if (comparison_sign == "<=") {
        isValid = (fieldValue <= value);
    } else if (comparison_sign == "==") {
        isValid = (fieldValue == value);
    } else {
        throw std::invalid_argument(
            "Invalid comparison sign: " + comparison_sign);
    }
    if (!isValid) {
        throw std::invalid_argument("The value of field '" + field_name
            + "' is not within the specified range.");
    }
}

void Sphere::checkJsonExistencePrimitive(
    const json& scene)
{
    checkJsonExistence(scene, "center");
    checkJsonExistence(scene["center"], "x");
    checkJsonExistence(scene["center"], "y");
    checkJsonExistence(scene["center"], "z");
    checkJsonExistence(scene, "radius");
    checkRangeValue(scene, "radius", ">", 0);
    checkJsonExistence(scene, "color");
    checkJsonExistence(scene["color"], "r");
    checkJsonExistence(scene["color"], "g");
    checkJsonExistence(scene["color"], "b");
    checkRangeValue(scene["color"], "r", ">=", 0);
    checkRangeValue(scene["color"], "g", ">=", 0);
    checkRangeValue(scene["color"], "b", ">=", 0);
    checkRangeValue(scene["color"], "r", "<=", 255);
    checkRangeValue(scene["color"], "g", "<=", 255);
    checkRangeValue(scene["color"], "b", "<=", 255);
    checkJsonExistence(scene, "reflection");
    checkRangeValue(scene, "reflection", ">=", 0);
    checkRangeValue(scene, "reflection", "<=", 1);
    checkJsonExistence(scene, "spec");
    checkRangeValue(scene, "spec", ">=", -1);
    checkJsonExistence(scene, "transparency");
    checkRangeValue(scene, "transparency", ">=", 0);
    checkRangeValue(scene, "transparency", "<=", 1);
}

void Sphere::parseInfo(json object)
{
    RayTracer::Color color(0, 0, 0);
    double reflect = 0.0;
    int specular = 0;
    double transparency = 0;
    // On récupère les infos de l'objet sphere
    checkJsonExistencePrimitive(object);
    this->center_.x = object["center"]["x"];
    this->center_.y = object["center"]["y"];
    this->center_.z = object["center"]["z"];
    this->radius_ = object["radius"];
    // On récupère les infos de la matière de la sphère
    color.r = object["color"]["r"];
    color.g = object["color"]["g"];
    color.b = object["color"]["b"];
    reflect = object["reflection"];
    specular = object["spec"];
    transparency = object["transparency"];
    // On set la matière de la sphère
    this->setMaterial(color, reflect, specular, transparency);
}

}
