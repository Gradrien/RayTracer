/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** APrimitives
*/

#ifndef RAYTRACER_APRIMITIVES_HPP
#define RAYTRACER_APRIMITIVES_HPP
#include "IPrimitives.hpp"
#define PI_RAD 3.14159265 / 180

namespace RayTracer {
/****************************************************************
 * @class APrimitives
 * @brief Abstract class for the primitives
 * @note  All the primitives must inherit from this class
 *****************************************************************/

class APrimitives : public IPrimitives {
  public:
    ~APrimitives() override = default;
    /****************************************************************
     * @brief getMaterial
     * @note get the material of the primitive
     * @retval the material
     *****************************************************************/
    Material getMaterial() final;
    /****************************************************************
     * @brief setMaterial
     * @note set the material of the primitive
     * @param color: the color of the primitive
     * @param reflect: the reflect of the primitive
     * @param specular: the specular of the primitive
     * @param transparency: the transparency of the primitive
     ****************************************************************/
    void setMaterial(
        Color color, double reflect, int specular, double transparency) final;

  protected:
    Material material_;
};
} // namespace RayTracer

#endif // RAYTRACER_APRIMITIVES_HPP
