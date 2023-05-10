/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "APrimitives.hpp"
#include "Color.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include <vector>

namespace RayTracer {
/****************************************************************
 * @class Cylinder
 * @brief Cylinder primitive
 **************************************************************/
class Cylinder : public RayTracer::APrimitives {
  public:
    Cylinder(Math::Point3D crossingPoint, double radius);
    Cylinder() = default;
    /****************************************************************
     * @brief getIntersection
     * @note get the intersection between the primitive and the ray
     * @param camOrigin: the origin of the ray
     * @param rayDirection: the direction of the ray
     * @retval the intersection
     ****************************************************************/
    std::vector<double> getIntersection(RayTracer::Ray ray) final;
    /****************************************************************
     * @brief getNormalVector
     * @note get the normal vector of the primitive
     * @param point: the point where the normal vector is calculated
     * @retval the normal vector
     ****************************************************************/
    Math::Vector3D getNormalVector(Math::Point3D point) final;
    /****************************************************************
     * @brief parseInfo
     * @note parse the info of the primitive and set the private attributes
     * @param object: the json object
     ****************************************************************/
    void parseInfo(json object) final;
    /****************************************************************
     * @brief  getRotationVector
     * @note   get the rotation vector of the primitive
     * @retval the rotation vector
     ****************************************************************/
    Math::Vector3D getRotationVector();
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
     * @note check if the field of a primitive exists in the json object
     * @param scene: the json object
     * @param field_name: the field name
     ****************************************************************/
    void checkJsonExistencePrimitive(
        const json& scene);
    void checkRangeValue(const json& scene, const std::string& field_name,
        const std::string& comparison_sign, double value);
    Math::Point3D crossingPoint_;
    Math::Vector3D rotation_;
    double radius_;
};
}

#endif /* !CYLINDER_HPP_ */
