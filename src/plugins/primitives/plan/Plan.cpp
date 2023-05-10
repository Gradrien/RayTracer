/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plan
*/

#include "Plan.hpp"

namespace RayTracer {

Plan::Plan(Math::Vector3D normalVector, double d)
    : normalVector_(normalVector)
    , d(d)
{
}

std::vector<double> Plan::getIntersection(RayTracer::Ray ray)
{
    ray.rotateRay(this->rotation_.x, this->rotation_.y, this->rotation_.z);

    double t = -(ray.origin.x * this->normalVector_.x
                   + ray.origin.y * this->normalVector_.y
                   + ray.origin.z * this->normalVector_.z - this->d)
        / (this->normalVector_.x * ray.direction.x
            + this->normalVector_.y * ray.direction.y
            + this->normalVector_.z * ray.direction.z);
    return { t };
}

Math::Vector3D Plan::getNormalVector(Math::Point3D point)
{
    (void)point;
    return this->normalVector_;
}

Math::Vector3D Plan::getRotationVector() {
    return this->rotation_;
}

void Plan::checkJsonExistence(
    const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument(
            "Le champ JSON '" + field_name + "' n'existe pas.");
}

void Plan::checkRangeValue(const json& scene, const std::string& field_name,
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

void Plan::checkJsonExistencePrimitive(
    const json& scene)
{
    checkJsonExistence(scene, "normal");
    checkJsonExistence(scene["normal"], "x");
    checkJsonExistence(scene["normal"], "y");
    checkJsonExistence(scene["normal"], "z");
    checkJsonExistence(scene, "translation");
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

void Plan::parseInfo(json object)
{
    RayTracer::Color color(0, 0, 0);
    double reflect = 0.0;
    int specular = 0;
    double transparency = 0;

    this->checkJsonExistencePrimitive(object);
    // On récupère les infos de l'objet plan
    this->normalVector_.x = object["normal"]["x"];
    this->normalVector_.y = object["normal"]["y"];
    this->normalVector_.z = object["normal"]["z"];
    this->d = object["translation"];
    this->rotation_.x = object["rotation"]["x"];
    this->rotation_.y = object["rotation"]["y"];
    this->rotation_.z = object["rotation"]["z"];

    this->rotation_ = rotation_ * PI_RAD;
    // On récupère les infos de la matière du plan
    color.r = object["color"]["r"];
    color.g = object["color"]["g"];
    color.b = object["color"]["b"];
    reflect = object["reflection"];
    specular = object["spec"];
    transparency = object["transparency"];
    // On set la matière du plan
    this->setMaterial(color, reflect, specular, transparency);
}

}
