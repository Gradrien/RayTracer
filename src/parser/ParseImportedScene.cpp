/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ParseImportedScene
*/

#include "Parser.hpp"

namespace RayTracer {

void Parser::parseObject(const std::string &name, json object, const std::string& key)
{
    for (const auto& [key2, object2] : object.items()) {
        if (scene_[name][key].contains(key2)) {
            if (object2.is_number()) {
                scene_[name][key][key2] = object2;
            } else {
                scene_[name][key][key2].insert(
                    scene_[name][key][key2].end(), object2.begin(),
                    object2.end());
            }
        } else {
            scene_[name][key][key2] = object2;
        }
    }
}

void Parser::parseImportedObj(const std::string &name)
{
    if (!importedScene_.contains(name))
        return;
    for (const auto& [key, object] : importedScene_[name].items()) {
        if (object.is_object()) {
            parseObject(name, object, key);
        } else {
            if (scene_[name].contains(key)) {
                scene_[name][key].insert(
                    scene_[name][key].end(), object.begin(), object.end());
            } else {
                scene_[name][key] = object;
            }
        }
    }
}

void Parser::parseImportedGlobal()
{
    if (!importedScene_.contains("global"))
        return;
    for (const auto& [key, object] : importedScene_["global"].items()) {
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
        if (key == "scene")
            std::cout << "Raytracer: warning: Cannot import recursively "
                      << object << std::endl;
    }
}

void Parser::parseImportedScene()
{
    parseImportedGlobal();
    parseImportedObj("camera");
    parseImportedObj("primitives");
    parseImportedObj("lights");
}
}