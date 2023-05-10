/*
** EPITECH PROJECT, 2023
** reworkRayTracer
** File description:
** Renderer
*/

#include "Renderer.hpp"

namespace RayTracer {

Math::Vector3D FastRenderer::reflectRay(
    Math::Vector3D normalVector, Math::Vector3D ray)
{
    return (normalVector * normalVector.dot(ray) * 2) - ray;
}

Color FastRenderer::computeLight(Math::Point3D intersectionPoint,
    Math::Vector3D normalVector, Math::Vector3D rayDir, int spec)
{
    Math::Vector3D L;
    Color i = { 0, 0, 0 };

    for (size_t it = 0; it < this->scene_.getLights().size(); it++) {
        i = i
            + this->scene_.getLights()[it]->computeFast(normalVector, spec,
                intersectionPoint, rayDir, this->scene_.getPrimitives());
    }
    return i;
}

intersection FastRenderer::getClosestIntersection(
    RayTracer::Ray ray, double tMin, double tMax)
{
    size_t closestInterIndex = 0;
    double closestT = -1;

    for (size_t i = 0; i < this->scene_.getPrimitives().size(); i++) {
        std::vector<double> hitVector {};
        IPrimitives& prim = *this->scene_.getPrimitives()[i];
        hitVector = prim.getIntersection(ray);
        for (double hitDist : hitVector) {
            if ((hitDist >= tMin && hitDist <= tMax)
                && (closestT == -1 || hitDist < closestT)) {
                closestT = hitDist;
                closestInterIndex = i;
            }
        }
    }
    return { *this->getScene().getPrimitives()[closestInterIndex], closestT };
}

Color FastRenderer::traceRay(
    RayTracer::Ray ray, double tMin, double tMax, int recursionDepth)
{
    intersection closestInter = getClosestIntersection(ray, tMin, tMax);
    if (closestInter.closestT == -1)
        return this->scene_.getCamera().getBackgroundColor();

    RayTracer::Ray raySave = ray;

    Math::Point3D pointSave;
    pointSave.x = ray.origin.x + (ray.direction.x * closestInter.closestT);
    pointSave.y = ray.origin.y + (ray.direction.y * closestInter.closestT);
    pointSave.z = ray.origin.z + (ray.direction.z * closestInter.closestT);

    Math::Vector3D normalVectorSave
        = closestInter.closestPrim.getNormalVector(pointSave);

    Math::Vector3D rotationVector
        = closestInter.closestPrim.getRotationVector();
    ray.rotateRay(rotationVector.x, rotationVector.y, rotationVector.z);

    Math::Point3D intersectionPoint;
    intersectionPoint.x
        = ray.origin.x + (ray.direction.x * closestInter.closestT);
    intersectionPoint.y
        = ray.origin.y + (ray.direction.y * closestInter.closestT);
    intersectionPoint.z
        = ray.origin.z + (ray.direction.z * closestInter.closestT);

    Math::Vector3D normalVector
        = closestInter.closestPrim.getNormalVector(intersectionPoint);

    Color lightIntensity = this->computeLight(intersectionPoint, normalVector,
        ray.direction * -1,
        closestInter.closestPrim.getMaterial().getSpecular());
    Color localColor = {
        closestInter.closestPrim.getMaterial().getColor().r * lightIntensity.r,
        closestInter.closestPrim.getMaterial().getColor().g * lightIntensity.g,
        closestInter.closestPrim.getMaterial().getColor().b * lightIntensity.b
    };

    double transparency
        = closestInter.closestPrim.getMaterial().getTransparency();

    Color transparencyColor { 0, 0, 0 };
    if (transparency > 0) {
        transparencyColor = traceRay({ pointSave, raySave.direction }, 0.001,
            DBL_MAX, recursionDepth - 1);
    }

    Color colorWithTransparency = { round(localColor.r * (1 - transparency)
                                        + transparencyColor.r * transparency),
        round(localColor.g * (1 - transparency)
            + transparencyColor.g * transparency),
        round(localColor.b * (1 - transparency)
            + transparencyColor.b * transparency) };
    return colorWithTransparency;
}

void FastRenderer::computeScene()
{
    for (; this->y > -(this->scene_.getCamera().imageSize_.height / 2);
         this->y -= 2) {
        for (; this->x < (this->scene_.getCamera().imageSize_.width / 2);
             this->x += 2) {
            if (this->index == this->result_.size())
                this->result_.emplace_back();
            Math::Vector3D D = this->scene_.getCamera().canvasToViewport(x, y);
            D.rotate(this->scene_.getCamera().rotation_.x,
                this->scene_.getCamera().rotation_.y,
                this->scene_.getCamera().rotation_.z);
            Color color = this->traceRay({ this->scene_.getCamera().origin, D },
                1, DBL_MAX, this->scene_.getCamera().reccursionDepth_);
            this->result_[this->index].emplace_back(color);
            this->result_[this->index].emplace_back(color);
            if (isCommand()) {
                this->x += 2;
                return;
            }
        }
        this->result_.emplace_back(this->result_[this->index]);
        this->x = -(this->scene_.getCamera().imageSize_.width / 2);
        this->index += 2;
    }
    this->done_ = true;
    this->canWrite_ = true;
}

void FastRenderer::initIterators()
{
    this->canWrite_ = false;
    this->done_ = false;
    this->index = 0;
    this->y = this->scene_.getCamera().imageSize_.height / 2;
    this->x = -(this->scene_.getCamera().imageSize_.width / 2);
}

bool FastRenderer::isCommand()
{
    fd_set rfds;
    struct timeval tv;
    FD_SET(0, &rfds);

    tv.tv_sec = 0;
    tv.tv_usec = 0;
    if (select(1, &rfds, NULL, NULL, &tv) > 0)
        return true;
    return false;
}

bool FastRenderer::isGenerationDone() { return this->done_; }

Scene& FastRenderer::getScene() { return this->scene_; }

std::vector<std::vector<Color>> FastRenderer::getResult()
{
    return this->result_;
}

bool FastRenderer::canWrite() { return this->canWrite_; }
}
