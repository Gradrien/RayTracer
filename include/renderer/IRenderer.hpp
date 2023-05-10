/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IRenderer
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP
#include "Point3D.hpp"
#include "RayTracer.hpp"
#include "Scene.hpp"
#include "Vector3D.hpp"
#include <cfloat>
#include <cmath>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <vector>

namespace RayTracer {
class IRenderer {
  public:
    /**
     * @brief Compute the scene and render the result.
     */
    virtual void computeScene() = 0;
    /**
     * @brief Get the result of the rendering as a 2D vector of colors.
     * @return The result of the rendering as a 2D vector of colors.
     */
    virtual std::vector<std::vector<Color>> getResult() = 0;
    /**
     * @brief Get the scene used for rendering.
     * @return The scene used for rendering.
     */
    virtual Scene& getScene() = 0;
    /**
     * @brief Initializes the iterators for generation
     */
    virtual void initIterators() = 0;
    /**
     * @brief Checks if the generation process is done
     *
     * @return True if the generation is done, False otherwise
     */
    virtual bool isGenerationDone() = 0;
    /**
     * @brief Checks if writing is allowed
     *
     * @return True if writing is allowed, False otherwise
     */
    virtual bool canWrite() = 0;
    /**
     * @brief Checks if the current action is a command
     *
     * @return True if the current action is a command, False otherwise
     */
    virtual bool isCommand() = 0;
};
} // namespace RayTracer

#endif // RAYTRACER_IRENDERER_HPP
