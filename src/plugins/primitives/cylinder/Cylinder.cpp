/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include <cmath>

namespace RayTracer {
Cylinder::Cylinder(Math::Point3D crossingPoint, double radius)
{
    this->crossingPoint_ = crossingPoint;
    this->radius_ = radius;
}

std::vector<double> Cylinder::getIntersection(RayTracer::Ray ray)
{
    ray.origin.y -= this->crossingPoint_.y;

    ray.rotateRay(this->rotation_.x, this->rotation_.y, this->rotation_.z);

    double a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
    double b = 2 * ray.origin.x * ray.direction.x
        + 2 * ray.origin.z * ray.direction.z
        - 2 * ray.direction.x * this->crossingPoint_.x
        - 2 * ray.direction.z * this->crossingPoint_.z;
    double c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2)
        - 2 * ray.origin.x * this->crossingPoint_.x
        - 2 * ray.origin.z * this->crossingPoint_.z
        + pow(this->crossingPoint_.x, 2) + pow(this->crossingPoint_.z, 2)
        - pow(this->radius_, 2);
    double delta = pow(b, 2) - (4 * a * c);

    if (delta < 0)
        return {};
    if (delta == 0)
        return { -b / (2 * a) };

    return { (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a) };
}

Math::Vector3D Cylinder::getNormalVector(Math::Point3D point)
{
    Math::Vector3D normal;
    normal.x = point.x - this->crossingPoint_.x;
    normal.y = 0;
    normal.z = point.z - this->crossingPoint_.z;
    normal = normal / normal.length();
    return normal;
}

Math::Vector3D Cylinder::getRotationVector() {
    return this->rotation_;
}

void Cylinder::checkJsonExistence(const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument(
            "Le champ JSON '" + field_name + "' n'existe pas.");
}

void Cylinder::checkRangeValue(const json& scene, const std::string& field_name,
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

void Cylinder::checkJsonExistencePrimitive(const json& scene)
{
    checkJsonExistence(scene, "crossing_point");
    checkJsonExistence(scene["crossing_point"], "x");
    checkJsonExistence(scene["crossing_point"], "y");
    checkJsonExistence(scene["crossing_point"], "z");
    checkJsonExistence(scene, "radius");
    checkRangeValue(scene, "radius", ">", 0);
    checkJsonExistence(scene, "rotation");
    checkJsonExistence(scene["rotation"], "x");
    checkJsonExistence(scene["rotation"], "y");
    checkJsonExistence(scene["rotation"], "z");
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

void Cylinder::parseInfo(json object)
{
    RayTracer::Color color(0, 0, 0);
    double reflect = 0.0;
    int specular = 0;
    double transparency = 0;

    this->checkJsonExistencePrimitive(object);
    // On récupère les infos de l'objet cylindre
    this->crossingPoint_.x = object["crossing_point"]["x"];
    this->crossingPoint_.y = object["crossing_point"]["y"];
    this->crossingPoint_.z = object["crossing_point"]["z"];
    this->radius_ = object["radius"];
    this->rotation_.x = object["rotation"]["x"];
    this->rotation_.y = object["rotation"]["y"];
    this->rotation_.z = object["rotation"]["z"];

    this->rotation_ = this->rotation_ * PI_RAD;
    // On récupère les infos de la matière du cylindre
    color.r = object["color"]["r"];
    color.g = object["color"]["g"];
    color.b = object["color"]["b"];
    reflect = object["reflection"];
    specular = object["spec"];
    transparency = object["transparency"];
    // On set la matière du cylindre
    this->setMaterial(color, reflect, specular, transparency);
}
}
