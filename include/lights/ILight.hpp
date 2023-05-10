/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ILight
*/

#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP
#include "IPrimitives.hpp"
#include "Point3D.hpp"
#include "RayTracer.hpp"
#include "Vector3D.hpp"
#include <cfloat>
#include <cmath>
#include <memory>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace RayTracer {
/****************************************************************
 * @class ILight
 * @brief Abstract class for the lights
 * @note  All the lights must inherit from this class
 *****************************************************************/
class ILight {
  public:
    virtual ~ILight() = default;
    /****************************************************************
     * @brief  isShadowIntersection
     * @note   check if there is an intersection between the light and the
     *primitive
     * @param  intersectionPoint: the intersection point
     * @param  primitives: the primitives
     * @retval true if there is an intersection, false otherwise
     ****************************************************************/
    virtual bool isShadowIntersection(Math::Point3D intersectionPoint,
        std::vector<std::unique_ptr<IPrimitives>>& primitives)
        = 0;
    /****************************************************************
     * @brief  getClosestIntersection
     * @note   get the closest intersection between the light and the primitive
     * @param  camOrigin: the origin of the ray
     * @param  ray: the direction of the ray
     * @param  tMin: the minimum distance
     * @param  tMax: the maximum distance
     * @param  primitives: the primitives
     * @retval the intersection
     ****************************************************************/
    virtual intersection getClosestIntersection(RayTracer::Ray ray, double tMin, double tMax,
        std::vector<std::unique_ptr<IPrimitives>>& primitives)
        = 0;
    /************************************************************************************************
     * @brief  computeDiffuseLight
     * @note   compute the diffuse light
     * @param  normalVector: the normal vector
     * @retval the diffuse light
     ************************************************************************************************/
    virtual Color computeDiffuseLight(Math::Vector3D normalVector) = 0;
    /************************************************************************************************
     * @brief  computeSpecular
     * @note   compute the specular light
     * @param  normalVector: the normal vector
     * @param  spec: the specular
     * @param  rayDir: the direction of the ray
     * @retval the specular effect color
     ************************************************************************************************/
    virtual Color computeSpecular(
        Math::Vector3D normalVector, int spec, Math::Vector3D rayDir)
        = 0;
    /************************************************************************************************
     * @brief  computeLight
     * @note   compute the light
     * @param  normalVector: the normal vector
     * @param  spec: the specular
     * @param  intersectionPoint: the intersection point
     * @param  rayDir: the direction of the ray
     * @param  primitives: the primitives
     * @retval the light
     ************************************************************************************************/
    virtual Color computeLight(Math::Vector3D normalVector, int spec,
        Math::Point3D intersectionPoint, Math::Vector3D rayDir,
        std::vector<std::unique_ptr<IPrimitives>>& primitives)
        = 0;

    virtual Color computeFast(Math::Vector3D normalVector, int spec,
        Math::Point3D intersectionPoint, Math::Vector3D rayDir,
        std::vector<std::unique_ptr<IPrimitives>>& primitives) = 0;

    /**
     * @brief Information parser to create the light object
     * @param object the json object containing light info
     */
    virtual void parseInfo(json object) = 0;
};
}

#endif // RAYTRACER_ILIGHT_HPP
