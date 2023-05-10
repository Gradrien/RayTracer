/*
** EPITECH PROJECT, 2023
** reworkRayTracer
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "IRenderer.hpp"

namespace RayTracer {
class FastRenderer : public IRenderer {
  public:
    FastRenderer() = default;
    ~FastRenderer() = default;
    Color traceRay(
        RayTracer::Ray ray, double tMin, double tMax, int recursion_depth);
    Color computeLight(Math::Point3D intersectionPoint,
        Math::Vector3D normalVector, Math::Vector3D rayDir, int spec);
    intersection getClosestIntersection(
        RayTracer::Ray ray, double tMin, double tMax);
    Math::Vector3D reflectRay(Math::Vector3D normalVector, Math::Vector3D ray);
    std::vector<std::vector<Color>> getResult() override;
    void computeScene() override;
    Scene& getScene() override;
    void initIterators() override;
    bool isGenerationDone() override;
    bool isCommand() override;
    bool canWrite() override;

  private:
    Scene scene_ {};
    std::vector<std::vector<Color>> result_;
    double x;
    double y;
    std::size_t index = 0;
    bool done_ { false };
    bool canWrite_ { false };
};
}

#endif /* !RENDERER_HPP_ */
