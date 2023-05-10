/*
 ** EPITECH PROJECT, 2023
 ** raytracer
 ** File description:
 ** Cone
 */

#include "Cone.hpp"
#include <cmath>

namespace RayTracer {
Cone::Cone(Math::Point3D crossingPoint, double angle)
{
    this->crossingPoint_ = crossingPoint;
    this->angle_ = angle;
}

std::vector<double> Cone::getIntersection(RayTracer::Ray ray)
{
    ray.origin.y -= this->crossingPoint_.y;

    ray.rotateRay(this->rotation_.x, this->rotation_.y, this->rotation_.z);

    double a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2)
        - (pow(ray.direction.y, 2) * pow(tan(this->angle_), 2));
    double b = 2 * ray.origin.x * ray.direction.x
        + 2 * ray.origin.z * ray.direction.z
        - 2 * ray.origin.y * ray.direction.y * pow(tan(this->angle_), 2)
        - 2 * ray.direction.x * this->crossingPoint_.x
        - 2 * ray.direction.z * this->crossingPoint_.z;
    double c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2)
        - pow(ray.origin.y, 2) * pow(tan(this->angle_), 2)
        - 2 * ray.origin.x * this->crossingPoint_.x
        - 2 * ray.origin.z * this->crossingPoint_.z
        + pow(this->crossingPoint_.x, 2) + pow(this->crossingPoint_.z, 2);
    double delta = pow(b, 2) - (4 * a * c);

    if (delta < 0)
        return {};
    if (delta == 0)
        return { -b / (2 * a) };

    return { (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a) };
}

Math::Vector3D Cone::getNormalVector(Math::Point3D point)
{
    Math::Vector3D normal(2 * (point.x - this->crossingPoint_.x),
        -2 * pow(tan(this->angle_), 2) * (point.y - this->crossingPoint_.y),
        2 * (point.z - this->crossingPoint_.z));

    normal = normal / normal.length();
    return normal;
}

Math::Vector3D Cone::getRotationVector() {
    return this->rotation_;
}

void Cone::checkJsonExistence(const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument(
            "Le champ JSON '" + field_name + "' n'existe pas.");
}

void Cone::checkRangeValue(const json& scene, const std::string& field_name,
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

void Cone::checkJsonExistencePrimitive(const json& scene)
{
    checkJsonExistence(scene, "crossing_point");
    checkJsonExistence(scene["crossing_point"], "x");
    checkJsonExistence(scene["crossing_point"], "y");
    checkJsonExistence(scene["crossing_point"], "z");
    checkJsonExistence(scene, "angle");
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

void Cone::parseInfo(json object)
{
    RayTracer::Color color(0, 0, 0);
    double reflect = 0.0;
    int specular = 0;
    double transparency = 0;

    this->checkJsonExistencePrimitive(object);
    // On récupère les infos de l'objet cone
    this->crossingPoint_.x = object["crossing_point"]["x"];
    this->crossingPoint_.y = object["crossing_point"]["y"];
    this->crossingPoint_.z = object["crossing_point"]["z"];
    this->rotation_.x = object["rotation"]["x"];
    this->rotation_.y = object["rotation"]["y"];
    this->rotation_.z = object["rotation"]["z"];

    this->rotation_ = rotation_ * PI_RAD;

    this->angle_ = object["angle"];
    this->angle_ = angle_ * PI_RAD;
    // On récupère les infos de la matière du cone
    color.r = object["color"]["r"];
    color.g = object["color"]["g"];
    color.b = object["color"]["b"];
    reflect = object["reflection"];
    specular = object["spec"];
    transparency = object["transparency"];
    // On set la matière du cone
    this->setMaterial(color, reflect, specular, transparency);
}

}
// Other formulas :

// (2x - 2a, 2y - 2b, -2z * tan^2(alpha) + 2c)
// Math::Vector3D normal(2 * point.x - 2 * this->crossingPoint_.x,
//     2 * point.y - 2 * this->crossingPoint_.y,
//     -2 * point.z * pow(tan(this->angle_), 2) + 2 *
//     this->crossingPoint_.z);

// Math::Vector3D dir(0, 10, 0);
// Math::Vector3D point_;
// point_.x = point.x;
// point_.y = point.y;
// point_.z = point.z;

// Math::Vector3D normal
//     = point_ - (dir * (dir.dot(point_) / pow(dir.length(), 2)));
