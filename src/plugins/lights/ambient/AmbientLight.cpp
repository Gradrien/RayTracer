/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

namespace RayTracer {

AmbientLight::AmbientLight(Color color, double intensity)
{
    this->color_ = color;
    this->intensity_ = intensity;
}

Color AmbientLight::computeLight(Math::Vector3D normalVector, int spec, Math::Point3D intersectionPoint, Math::Vector3D rayDir, std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    (void) primitives;
    (void) normalVector;
    (void) spec;
    (void) intersectionPoint;
    (void) rayDir;
    return {this->color_.getRIntensity() * this->intensity_, this->color_.getGIntensity() * this->intensity_, this->color_.getBIntensity() * this->intensity_};
}

void AmbientLight::checkJsonExistence(
    const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument(
            "Le champ JSON '" + field_name + "' n'existe pas.");
}

void AmbientLight::checkJsonExistenceLight(const json& scene)
{
    checkJsonExistence(scene, "color");
    checkJsonExistence(scene["color"], "r");
    checkJsonExistence(scene["color"], "g");
    checkJsonExistence(scene["color"], "b");
    checkJsonExistence(scene, "intensity");
}

void AmbientLight::parseInfo(json object)
{
    this->checkJsonExistenceLight(object);
    this->intensity_ = object["intensity"];
    this->color_.r = object["color"]["r"];
    this->color_.g = object["color"]["g"];
    this->color_.b = object["color"]["b"];
}

Color AmbientLight::computeFast(Math::Vector3D normalVector, int spec, Math::Point3D intersectionPoint, Math::Vector3D rayDir, std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    return this->computeLight(normalVector, spec, intersectionPoint, rayDir, primitives);
}
}
