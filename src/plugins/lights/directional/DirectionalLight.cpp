/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

namespace RayTracer {
DirectionalLight::DirectionalLight(Color color, double intensity, Math::Vector3D direction)
{
    this->color_ = color;
    this->direction_ = direction;
    this->intensity_= intensity;
}

Color DirectionalLight::computeLight(Math::Vector3D normalVector, int spec,
    Math::Point3D intersectionPoint, Math::Vector3D rayDir,
    std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    Color i = { 0, 0, 0 };
    this->lightVector_ = this->direction_;
    if (this->isShadowIntersection(intersectionPoint, primitives))
        return {0, 0, 0};
    i = i + this->computeDiffuseLight(normalVector);
    i = i + this->computeSpecular(normalVector, spec, rayDir);
    return i;
}

void DirectionalLight::checkJsonExistence(
    const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument("Le champ JSON '" + field_name + "' n'existe pas.");
}

void DirectionalLight::checkJsonExistenceLight(const json& scene)
{
    checkJsonExistence(scene, "x");
    checkJsonExistence(scene, "y");
    checkJsonExistence(scene, "z");
    checkJsonExistence(scene, "color");
    checkJsonExistence(scene["color"], "r");
    checkJsonExistence(scene["color"], "g");
    checkJsonExistence(scene["color"], "b");
    checkJsonExistence(scene, "intensity");
}

void DirectionalLight::parseInfo(json object)
{
    this->checkJsonExistenceLight(object);
    this->intensity_ = object["intensity"];
    this->direction_.x = object["x"];
    this->direction_.y = object["y"];
    this->direction_.z = object["z"];
    this->direction_ = this->direction_ * -1;
    this->color_.r = object["color"]["r"];
    this->color_.g = object["color"]["g"];
    this->color_.b = object["color"]["b"];
}

Color DirectionalLight::computeFast(Math::Vector3D normalVector, int spec, Math::Point3D intersectionPoint, Math::Vector3D rayDir, std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    (void) spec;
    (void) intersectionPoint;
    (void) primitives;
    (void) rayDir;
    this->lightVector_ = this->direction_;
    return this->computeDiffuseLight(normalVector);
}
}
