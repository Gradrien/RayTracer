/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plan
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include "APrimitives.hpp"
#include "Ray.hpp"
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;
namespace RayTracer {
class Plan : public RayTracer::APrimitives {
  public:
    Plan() = default;
    Plan(Math::Vector3D normalVector, double d);
    Plan(Plan&) = default;
    Plan(Plan&&) = default;
    Plan& operator=(const Plan&) = default;
    Plan& operator=(Plan&&) = default;
    /****************************************************************
     * @brief getIntersection
     * @note get the intersection of the ray with the primitive
     * @param ray: the ray
     * @return the intersection point
     ****************************************************************/
    std::vector<double> getIntersection(RayTracer::Ray ray) final;
    /****************************************************************
     * @brief getNormalVector
     * @note get the normal vector of the primitive
     * @param point: the intersection point
     * @return the normal vector
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
    Math::Vector3D normalVector_;
    Math::Vector3D rotation_;
    double d;
};
}

#endif /* !PLAN_HPP_ */
