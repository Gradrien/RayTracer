/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IPrimitives
*/

#ifndef RAYTRACER_IPRIMITIVES_HPP
#define RAYTRACER_IPRIMITIVES_HPP

#include "Material.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;
namespace RayTracer {
/*****************************************************************
 * @class IPrimitives
 * @brief Interface for the primitives
 *****************************************************************/
class IPrimitives {
  public:
    virtual ~IPrimitives() = default;
    /****************************************************************
     * @brief  getIntersection
     * @note   get the intersection between the primitive and the ray
     * @param  camOrigin the origin of the ray
     * @param  rayDirection the direction of the ray
     * @retval the intersection
     ****************************************************************/
    virtual std::vector<double> getIntersection(RayTracer::Ray ray) = 0;
    /****************************************************************
     * @brief  getNormalVector
     * @note   get the normal vector of the primitive
     * @param  point the point where the normal vector is calculated
     * @retval the normal vector
     ****************************************************************/
    virtual Math::Vector3D getNormalVector(Math::Point3D point) = 0;
    /****************************************************************
     * @brief  getMaterial
     * @note   get the material of the primitive
     * @retval the material
     *****************************************************************/
    virtual Material getMaterial() = 0;
    /****************************************************************
     * @brief  setMaterial
     * @note   set the material of the primitive
     * @param  color the color of the primitive
     * @param  reflect the reflect of the primitive
     * @param  specular the specular of the primitive
     * @param  transparency the transparency of the primitive
     ****************************************************************/
    virtual void setMaterial(
        Color color, double reflect, int specular, double transparency)
        = 0;
    /****************************************************************
     * @brief  parseInfo
     * @note   parse the info of the primitive and set the private attributes
     * @param  object the json object
     ****************************************************************/
    virtual void parseInfo(json object) = 0;
    /****************************************************************
     * @brief  getRotationVector
     * @note   get the rotation vector of the primitive
     * @retval the rotation vector
     ****************************************************************/
    virtual Math::Vector3D getRotationVector() = 0;
};
}

#endif // RAYTRACER_IPRIMITIVES_HPP
