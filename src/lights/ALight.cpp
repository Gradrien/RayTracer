/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ALight
*/

#include "ALight.hpp"

namespace RayTracer {

Color ALight::computeDiffuseLight(Math::Vector3D normalVector)
{
    double n_dot_l = normalVector.dot(this->lightVector_);
    if (n_dot_l > 0) {
        return { this->color_.getRIntensity() * this->intensity_ * n_dot_l
                / (normalVector.length() * this->lightVector_.length()),
            this->color_.getGIntensity() * this->intensity_ * n_dot_l
                / (normalVector.length() * this->lightVector_.length()),
            this->color_.getBIntensity() * this->intensity_ * n_dot_l
                / (normalVector.length() * this->lightVector_.length()) };
    }
    return { 0, 0, 0 };
}

Color ALight::computeSpecular(
    Math::Vector3D normalVector, int spec, Math::Vector3D rayDir)
{
    if (spec == -1)
        return { 0, 0, 0 };
    Math::Vector3D R = (normalVector * normalVector.dot(this->lightVector_) * 2)
        - this->lightVector_;
    double r_dot_v = R.dot(rayDir);
    if (r_dot_v > 0) {
        return {
            (this->color_.getRIntensity() * this->intensity_
                * pow(r_dot_v / (R.length() * rayDir.length()), spec)),
            (this->color_.getGIntensity() * this->intensity_
                * pow(r_dot_v / (R.length() * rayDir.length()), spec)),
            (this->color_.getBIntensity() * this->intensity_
                * pow(r_dot_v / (R.length() * rayDir.length()), spec)),
        };
    }
    return { 0, 0, 0 };
}

bool ALight::isShadowIntersection(Math::Point3D intersectionPoint,
    std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    intersection shadowInter = this->getClosestIntersection(
        { intersectionPoint, this->lightVector_ }, 0.001, DBL_MAX, primitives);
    if (shadowInter.closestT != -1)
        return true;
    return false;
}

intersection ALight::getClosestIntersection(RayTracer::Ray ray, double tMin,
    double tMax, std::vector<std::unique_ptr<IPrimitives>>& primitives)
{
    size_t closestInterIndex = 0;
    double closestT = -1;

    for (size_t i = 0; i < primitives.size(); i++) {
        std::vector<double> hitVector {};
        IPrimitives& prim = *primitives[i];
        hitVector = prim.getIntersection(ray);
        for (double hitDist : hitVector) {
            if ((hitDist >= tMin && hitDist <= tMax)
                && (closestT == -1 || hitDist < closestT)) {
                closestT = hitDist;
                closestInterIndex = i;
            }
        }
    }
    return { *primitives[closestInterIndex], closestT };
}
}
