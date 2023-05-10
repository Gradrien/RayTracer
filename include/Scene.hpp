/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene
*/

#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP
#include "Camera.hpp"
#include "IPrimitives.hpp"
#include "ILight.hpp"
#include <memory>

/**
 * @namespace RayTracer
 * @brief Namespace for the raytracer
 */
namespace RayTracer {
/**
 * @class Scene
 * @brief Class for the scene
 */
class Scene {
public:
  Scene() = default;
  ~Scene() = default;
  /**
   * @brief Adds a new primitive object to the scene.
   *
   * @param prim A unique pointer to the primitive object to add.
   **/
  void addPrimitive(std::unique_ptr<IPrimitives> prim);
  /**
   * @brief Returns a reference to the vector of primitives in the scene.
   *
   * @return A reference to the vector of unique pointers to the primitives in
   * the scene.
   */
  std::vector<std::unique_ptr<IPrimitives>> &getPrimitives();
  /**
   * @brief Adds a new light source to the scene.
   *
   * @param light A unique pointer to the light source to add.
   */
  void addLight(std::unique_ptr<ILight> light);
  /**
   * @brief Returns a reference to the vector of light sources in the scene.
   *
   * @return A reference to the vector of unique pointers to the light sources
   * in the scene.
   */
  std::vector<std::unique_ptr<ILight>> &getLights();
  /**
   * @brief Returns a reference to the camera object in the scene.
   *
   * @return A reference to the camera object in the scene.
   */
  Camera &getCamera();
  /**
   * @brief Sets the camera object in the scene.
   *
   * @param cam The new camera object to set.
   */
  void setCamera(Camera cam);

private:
  std::vector<std::unique_ptr<IPrimitives>> primitives_;
  std::vector<std::unique_ptr<ILight>> lights_;
  Camera cam_{};
};
} // namespace RayTracer

#endif // RAYTRACER_SCENE_HPP
