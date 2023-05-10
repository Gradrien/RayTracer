/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Scene
*/

#include "Scene.hpp"

namespace RayTracer {
void Scene::addPrimitive(std::unique_ptr<IPrimitives> prim)
{
    this->primitives_.emplace_back(std::move(prim));
}

void Scene::setCamera(RayTracer::Camera cam)
{
    this->cam_ = cam;
}

Camera& Scene::getCamera()
{
    return this->cam_;
}

std::vector<std::unique_ptr<IPrimitives>>& Scene::getPrimitives()
{
    return this->primitives_;
}

void Scene::addLight(std::unique_ptr<ILight> light)
{
    this->lights_.emplace_back(std::move(light));
}

std::vector<std::unique_ptr<ILight>>& Scene::getLights()
{
    return this->lights_;
}
}
