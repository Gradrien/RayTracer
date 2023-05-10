/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#ifndef RAYTRACER_POINTLIGHT_HPP
#define RAYTRACER_POINTLIGHT_HPP
#include "ALight.hpp"

namespace RayTracer {
/****************************************************************
 * @class PointLight
 * @brief PointLight class
 *****************************************************************/
class PointLight : public ALight {
  public:
    PointLight(Color color, double intensity, Math::Point3D origin);
    PointLight() = default;
    ~PointLight() override = default;
    /****************************************************************
     * @brief computeLight
     * @note compute the light of the primitive
     * @param normalVector: the normal vector of the primitive
     * @param spec: the specular of the primitive
     * @param intersectionPoint: the intersection point
     * @param rayDir: the direction of the ray
     * @param primitives: the primitives
     * @retval the light color
     ****************************************************************/
    Color computeLight(Math::Vector3D normalVector, int spec,
        Math::Point3D intersectionPoint, Math::Vector3D rayDir,
        std::vector<std::unique_ptr<IPrimitives>>& primitives) override;
    /****************************************************************
     * @brief parseInfo
     * @note parse the json object
     * @param object: the json object
     ****************************************************************/
    void parseInfo(json object) final;
    /****************************************************************
     * @brief computeFast
     * @note compute the light of the primitive
     * @param normalVector: the normal vector of the primitive
     * @param spec: the specular of the primitive
     * @param intersectionPoint: the intersection point
     * @param rayDir: the direction of the ray
     * @param primitives: the primitives
     * @retval the light color
     ****************************************************************/
    Color computeFast(Math::Vector3D normalVector, int spec,
        Math::Point3D intersectionPoint, Math::Vector3D rayDir,
        std::vector<std::unique_ptr<IPrimitives>>& primitives) final;

  private:
    /****************************************************************
     * @brief checkJsonExistence
     * @note check if the field exists in the json object
     * @param scene: the json object
     * @param field_name: the field name
     ****************************************************************/
    void checkJsonExistence(const json& scene, const std::string& field_name);
    /****************************************************************
     * @brief checkJsonExistencePrimitive
     * @note check if the field of a light exists in the json object
     * @param scene: the json object
     * @param field_name: the field name
     ****************************************************************/
    void checkJsonExistenceLight(const json& scene);
};
}

#endif // RAYTRACER_POINTLIGHT_HPP
