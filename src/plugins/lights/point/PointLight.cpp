/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#include "PointLight.hpp"

namespace RayTracer {
PointLight::PointLight(Color color, double intensity, Math::Point3D origin)
{
    this->color_ = color;
    this->origin_ = origin;
    this->intensity_ = intensity;
}

Color PointLight::computeLight(Math::Vector3D normalVector, int spec, Math::Point3D intersectionPoint, Math::Vector3D rayDir, std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    Color i = {0, 0, 0};
    this->lightVector_.x = this->origin_.x - intersectionPoint.x;
    this->lightVector_.y = this->origin_.y - intersectionPoint.y;
    this->lightVector_.z = this->origin_.z - intersectionPoint.z;
    if (this->isShadowIntersection(intersectionPoint, primitives))
        return {0, 0, 0};
    i = i + this->computeDiffuseLight(normalVector);
    i = i + this->computeSpecular(normalVector, spec, rayDir);
    return i;
}

void PointLight::checkJsonExistence(
    const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument(
            "Le champ JSON '" + field_name + "' n'existe pas.");
}

void PointLight::checkJsonExistenceLight(const json& scene)
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

void PointLight::parseInfo(json object)
{
    this->checkJsonExistenceLight(object);
    this->intensity_ = object["intensity"];
    this->origin_.x = object["x"];
    this->origin_.y = object["y"];
    this->origin_.z = object["z"];
    this->color_.r = object["color"]["r"];
    this->color_.g = object["color"]["g"];
    this->color_.b = object["color"]["b"];
}

Color PointLight::computeFast(Math::Vector3D normalVector, int spec, Math::Point3D intersectionPoint, Math::Vector3D rayDir, std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    (void) spec;
    (void) rayDir;
    (void) primitives;
    this->lightVector_.x = this->origin_.x - intersectionPoint.x;
    this->lightVector_.y = this->origin_.y - intersectionPoint.y;
    this->lightVector_.z = this->origin_.z - intersectionPoint.z;
    return this->computeDiffuseLight(normalVector);
}
}
