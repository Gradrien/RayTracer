/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser
*/

#include "Parser.hpp"

namespace RayTracer {
Parser::Parser(const std::string& path)
{
    if (path.empty() || !path.ends_with(".json"))
        throw ParsingError("Invalid file provided");

    std::ifstream f(path);

    std::cout << "Parsing:\n";
    scene_ = json::parse(f);
    parseCorePlugins();
}

void Parser::parseCamera(RayTracer::Camera& cam)
{
    if (!scene_.contains("camera"))
        return;
    this->checkJsonCamera(scene_);
    cam_.imageSize_.width = scene_["camera"]["resolution"]["width"];
    cam_.imageSize_.height = scene_["camera"]["resolution"]["height"];
    cam_.origin = Math::Point3D(scene_["camera"]["origin"]["x"],
        scene_["camera"]["origin"]["y"], scene_["camera"]["origin"]["z"]);
    cam_.screen.bottom_side
        = Math::Vector3D(scene_["camera"]["screen"]["width"], 0, 0);
    cam_.screen.left_side
        = Math::Vector3D(0, scene_["camera"]["screen"]["height"], 0);
    cam_.screen.origin.x = cam_.origin.x - cam_.screen.bottom_side.x / 2;
    cam_.screen.origin.y = cam_.origin.y - cam_.screen.left_side.y / 2;
    cam_.screen.origin.z = scene_["camera"]["screen"]["distance_with_camera"];
    cam_.rotation_ = Math::Vector3D(scene_["camera"]["rotation"]["x"],
        scene_["camera"]["rotation"]["y"], scene_["camera"]["rotation"]["z"]);
    cam_.rotation_ = cam_.rotation_ * PI_RAD;
    cam_.setBackgroundColor(Color(scene_["global"]["background_color"]["r"],
        scene_["global"]["background_color"]["g"],
        scene_["global"]["background_color"]["b"]));
    cam_.reccursionDepth_ = scene_["global"]["recursion_depth"];
    cam = cam_;
}

void Parser::parsePrimitive()
{
    if (!scene_.contains("primitives"))
        throw ParsingError("Error: No primitives found");
    for (auto& [key, object] : scene_["primitives"].items()) {
        for (auto& prim : object) {
            std::unique_ptr<IPrimitives> tmp = this->loadPrimitive(key);
            if (tmp == nullptr)
                throw ParsingError("Error: Primitive creation failed");
            tmp->parseInfo(prim);
            this->primitives_.push_back(std::move(tmp));
        }
    }
}

void Parser::parseLight()
{
    if (!scene_.contains("lights"))
        return;
    for (auto& [key, object] : scene_["lights"].items()) {
        for (auto& light : object) {
            std::unique_ptr<ILight> tmp = this->loadLight(key);
            if (tmp == nullptr)
                throw ParsingError("Error: Light creation failed");
            tmp->parseInfo(light);
            this->lights_.push_back(std::move(tmp));
        }
    }
}

void Parser::parseCorePlugins()
{
    if (!scene_.contains("global"))
        throw ParsingError("Error: Global section not found");
    this->checkJsonGlobal(scene_);
    for (auto& [key, object] : scene_["global"].items()) {
        if (key == "encoder_name")
            this->encoderName_ = object;
        if (key == "renderer_name")
            this->rendererName_ = object;
        if (key == "output_file")
            this->outputFile_ = object;
        if (key == "faster_render") {
            this->fasterRenderEnabled_ = true;
            this->fasterRenderName_ = object;
        }
        if (key == "scene") {
            std::cout << "Importing new scene " << object << std::endl;
            std::ifstream f(object);
            this->importedScene_ = json::parse(f);
            parseImportedScene();
            std::cout << "Scene imported\n";
        }
    }
}

void Parser::parse(RayTracer::Camera& cam)
{
    std::cout << "Camera:\n";
    parseCamera(cam);
    std::cout << "Camera parsed\n---\n";
    std::cout << "Primitives:\n";
    parsePrimitive();
    std::cout << "Primitives parsed\n---\n";
    std::cout << "lights:\n";
    parseLight();
    std::cout << "Light parsed\n---\n";
}

RayTracer::Camera Parser::getParsedCamera() { return cam_; }

std::unique_ptr<IPrimitives> Parser::loadPrimitive(const std::string& key)
{
    const std::filesystem::path libPath { "./plugins/primitives" };
    for (auto const& dir_entry :
        std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().stem().c_str()[0] == '.')
            continue;
        if (dir_entry.path().stem().c_str() != key)
            continue;
        return this->primitiveLoader_.getInstance(dir_entry.path());
    }
    return nullptr;
}

std::string Parser::getEncoderName() const { return this->encoderName_; }

std::string Parser::getRendererName() const { return this->rendererName_; }

std::string Parser::getOutputFileName() const { return this->outputFile_; }

std::string Parser::getFastRendererFileName() const
{
    return this->fasterRenderName_;
}

bool Parser::isFastRendererEnabled() const
{
    return this->fasterRenderEnabled_;
}

std::unique_ptr<ILight> Parser::loadLight(const std::string& key)
{
    const std::filesystem::path libPath { "./plugins/lights" };
    for (auto const& dir_entry :
        std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().stem().c_str()[0] == '.')
            continue;
        if (dir_entry.path().stem().c_str() != key)
            continue;
        return this->lightLoader_.getInstance(dir_entry.path());
    }
    return nullptr;
}
}
