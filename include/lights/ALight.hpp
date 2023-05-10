/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ALight
*/

#ifndef RAYTRACER_ALIGHT_HPP
#define RAYTRACER_ALIGHT_HPP
#include "ILight.hpp"
#include "Material.hpp"
#include "Ray.hpp"

namespace RayTracer {
/****************************************************************
 * @class ALight
 * @brief Abstract class for the lights
 * @note  All the lights must inherit from this class
 *****************************************************************/
class ALight : public ILight {
public:
  ~ALight() override = default;
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
  intersection getClosestIntersection(
      RayTracer::Ray ray, double tMin, double tMax,
      std::vector<std::unique_ptr<IPrimitives>> &primitives) final;
  /************************************************************************************************
   * @brief  computeDiffuseLight
   * @note   compute the diffuse light
   * @param  normalVector: the normal vector
   * @retval the diffuse light
   ************************************************************************************************/
  Color computeDiffuseLight(Math::Vector3D normalVector) final;
  /************************************************************************************************
   * @brief  computeSpecular
   * @note   compute the specular light
   * @param  normalVector: the normal vector
   * @param  spec: the specular
   * @param  rayDir: the direction of the ray
   * @retval the specular effect color
   ************************************************************************************************/
  Color computeSpecular(Math::Vector3D normalVector, int spec,
                        Math::Vector3D rayDir) final;
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
  bool isShadowIntersection(
      Math::Point3D intersectionPoint,
      std::vector<std::unique_ptr<IPrimitives>> &primitives) final;

protected:
  Math::Vector3D direction_{0, 0, 0};
  Math::Point3D origin_{0, 0, 0};
  Color color_{0, 0, 0};
  double intensity_{0.0};
  Math::Vector3D lightVector_{0, 0, 0};
};
} // namespace RayTracer

#endif // RAYTRACER_ALIGHT_HPP
