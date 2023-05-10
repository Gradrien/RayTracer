/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IParser
*/

#ifndef RAYTRACER_IPARSER_HPP
#define RAYTRACER_IPARSER_HPP

#include "Camera.hpp"
#include "ILight.hpp"

namespace RayTracer {
class IParser {
public:
  /**
   * @brief Parse the scene and fill the Camera object
   *
   * @param cam The Camera object to be filled
   */
  virtual void parse(RayTracer::Camera &cam) = 0;
  /**
   * @brief Get a vector of unique pointers to the scene primitives
   *
   * @return std::vector<std::unique_ptr<RayTracer::IPrimitives>>& Vector of
   * unique pointers to the scene primitives
   */
  virtual std::vector<std::unique_ptr<RayTracer::IPrimitives>> &
  getPrimitives() = 0;
  /**
   * @brief Get a vector of unique pointers to the scene lights
   *
   * @return std::vector<std::unique_ptr<RayTracer::ILight>>& Vector of unique
   * pointers to the scene lights
   */
  virtual std::vector<std::unique_ptr<RayTracer::ILight>> &getLights() = 0;
  /**
   * @brief Get the name of the encoder
   *
   * @return std::string The name of the encoder
   */
  virtual std::string getEncoderName() const = 0;
  /**
   * @brief Get the name of the renderer
   *
   * @return std::string The name of the renderer
   */
  virtual std::string getRendererName() const  = 0;
  /**
   * @brief Get the name of the output file
   *
   * @return std::string The name of the output file
   */
  virtual std::string getOutputFileName() const = 0;
  virtual std::string getFastRendererFileName() const = 0;
  virtual bool isFastRendererEnabled() const = 0;
};
} // namespace RayTracer

#endif // RAYTRACER_IPARSER_HPP
