/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CheckJsonExistence
*/

#include "Parser.hpp"

namespace RayTracer {
void Parser::checkJsonExistence(
    const json& scene, const std::string& field_name)
{
    if (!scene.contains(field_name))
        throw std::invalid_argument("Le champ JSON '" + field_name + "' n'existe pas.");
}

void Parser::checkRangeValue(const json& scene, const std::string& field_name, const std::string& comparison_sign, double value)
{
    double fieldValue = scene[field_name];
    bool isValid = false;

    if (comparison_sign == ">") {
        isValid = (fieldValue > value);
    } else if (comparison_sign == ">=") {
        isValid = (fieldValue >= value);
    } else if (comparison_sign == "<") {
        isValid = (fieldValue < value);
    } else if (comparison_sign == "<=") {
        isValid = (fieldValue <= value);
    } else if (comparison_sign == "==") {
        isValid = (fieldValue == value);
    } else {
        throw std::invalid_argument("Invalid comparison sign: " + comparison_sign);
    }
    if (!isValid) {
        throw std::invalid_argument("The value of field '" + field_name
            + "' is not within the specified range.");
    }
}

void Parser::checkJsonCamera(json scene)
{
    checkJsonExistence(scene["camera"], "resolution");
    checkJsonExistence(scene["camera"]["resolution"], "width");
    checkRangeValue(scene["camera"]["resolution"], "width", ">", 0);
    checkJsonExistence(scene["camera"]["resolution"], "height");
    checkRangeValue(scene["camera"]["resolution"], "height", ">", 0);
    checkJsonExistence(scene["camera"], "origin");
    checkJsonExistence(scene["camera"]["origin"], "x");
    checkJsonExistence(scene["camera"]["origin"], "y");
    checkJsonExistence(scene["camera"]["origin"], "z");
    checkJsonExistence(scene["camera"], "screen");
    checkJsonExistence(scene["camera"]["screen"], "width");
    checkRangeValue(scene["camera"]["screen"], "width", ">", 0);
    checkJsonExistence(scene["camera"]["screen"], "height");
    checkRangeValue(scene["camera"]["screen"], "height", ">", 0);
    checkJsonExistence(scene["camera"]["screen"], "distance_with_camera");
    checkRangeValue(scene["camera"]["screen"], "distance_with_camera", ">", 0);
}

void Parser::checkJsonGlobal(json scene)
{
    checkJsonExistence(scene, "global");
    checkJsonExistence(scene["global"], "background_color");
    checkJsonExistence(scene["global"]["background_color"], "r");
    checkJsonExistence(scene["global"]["background_color"], "g");
    checkJsonExistence(scene["global"]["background_color"], "b");
    checkRangeValue(scene["global"]["background_color"], "r", ">=", 0);
    checkRangeValue(scene["global"]["background_color"], "g", ">=", 0);
    checkRangeValue(scene["global"]["background_color"], "b", ">=", 0);
    checkRangeValue(scene["global"]["background_color"], "r", "<=", 255);
    checkRangeValue(scene["global"]["background_color"], "g", "<=", 255);
    checkRangeValue(scene["global"]["background_color"], "b", "<=", 255);
    checkJsonExistence(scene["global"], "recursion_depth");
    checkRangeValue(scene["global"], "recursion_depth", ">=", 0);
    checkJsonExistence(scene["global"], "encoder_name");
    checkJsonExistence(scene["global"], "renderer_name");
    checkJsonExistence(scene["global"], "output_file");
}
}
