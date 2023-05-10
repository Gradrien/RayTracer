/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Camera.hpp"
#include "DLLoader.hpp"
#include "Error.hpp"
#include "IParser.hpp"
#include "Point3D.hpp"
#include "fstream"
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @namespace RayTracer
 * @brief Namespace for the raytracer
 */
namespace RayTracer {
/**
 * @class Parser
 * @brief Class for the parser
 */
class Parser : public IParser {
  public:
    Parser() = default;
    explicit Parser(const std::string& path);
    ~Parser() = default;
    /**
     * @brief Parses the scene file and extracts the camera information
     * @param cam the camera object to store the parsed data
     */
    void parse(RayTracer::Camera& cam) final;
    /**
     * @brief Returns the parsed camera object
     * @return the parsed camera object
     */
    RayTracer::Camera getParsedCamera();
    /**
     * @brief Returns a reference to the vector of parsed primitives
     * @return the vector of parsed primitives
     */
    std::vector<std::unique_ptr<RayTracer::IPrimitives>>& getPrimitives() final;
    /**
     * @brief Returns a reference to the vector of parsed lights
     * @return the vector of parsed lights
     */
    std::vector<std::unique_ptr<RayTracer::ILight>>& getLights() final;

  private:
    /**
     * @brief Parses the camera information from the scene file
     * @param cam the camera object to store the parsed data
     */
    void parseCamera(RayTracer::Camera& cam);
    /**
     * @brief Parses primitive objects from the scene file
     */
    void parsePrimitive();
    /**
     * @brief Parses light objects from the scene file
     */
    void parseLight();
    /**
     * @brief Parses the core plugins from the scene file
     */
    void parseCorePlugins();
    /**
     * @brief Parses elements from the imported scene
     *
     */
    void parseImportedScene();
    /**
     * @brief Parses the "global" element from the imported scene
     *
     */
    void parseImportedGlobal();
    /**
     * @brief Parses objects from the imported scene
     * @param name the name of the object
     *
     */
    void parseImportedObj(const std::string& name);
    /**
     * @brief Parses a nested object from the imported scene
     * @param name the name of the object
     * @param object the object to parse
     * @param key the key of the object
     *
     */
    void parseObject(
        const std::string& name, json object, const std::string& key);
    /**
     * @brief Loads a primitive object based on the given key
     * @param key the key for the primitive object
     * @return a unique pointer to the parsed primitive object
     */
    std::unique_ptr<IPrimitives> loadPrimitive(const std::string& key);
    /**
     * @brief Loads a light object based on the given key
     * @param key the key for the light object
     * @return a unique pointer to the parsed light object
     */
    std::unique_ptr<ILight> loadLight(const std::string& key);
    /**
     * @brief Gets the name of the encoder
     * @return the name of the encoder
     */
    std::string getEncoderName() const final;
    /**
     * @brief Gets the name of the renderer
     * @return the name of the renderer
     */
    std::string getRendererName() const final;
    /**
     * @brief Gets the name of the output file
     * @return the name of the output file
     */
    std::string getOutputFileName() const final;
    /**
     * @brief Gets the name of the fast renderer
     * @return the name of the fast renderer
     */
    std::string getFastRendererFileName() const final;
    /**
     * @brief Checks if the fast renderer is enabled
     * @return true if the fast renderer is enabled, false otherwise
     */
    bool isFastRendererEnabled() const final;
    /**
     * @brief Checks if the given key exists in the scene file
     * @param scene the scene file
     * @param field_name the key to check
     */
    void checkJsonExistence(const json& scene, const std::string& field_name);
    /**
     * @brief Checks if the value of the given key is within the specified range
     * @param scene the scene file
     * @param field_name the key to check
     * @param comparison_sign the comparison sign
     * @param value the value to compare with
     */
    void checkRangeValue(const json& scene,
        const std::string& field_name, const std::string& comparison_sign,
        double value);
        /**
         * @brief Checks if the camera exists in the scene file
         * @param scene the scene file
         */
        void checkJsonCamera(json scene);
    /**
     * @brief Checks if the global exist in the scene file
     * @param scene the scene file
     */
    void checkJsonGlobal(json scene);
    json scene_ {};
    json importedScene_ {};
    RayTracer::Camera cam_;
    std::vector<std::unique_ptr<RayTracer::IPrimitives>> primitives_;
    std::vector<std::unique_ptr<RayTracer::ILight>> lights_;
    DLLoader<IPrimitives> primitiveLoader_;
    DLLoader<ILight> lightLoader_;
    std::string rendererName_;
    std::string encoderName_;
    std::string outputFile_;
    bool fasterRenderEnabled_ { false };
    std::string fasterRenderName_;
};
} // namespace RayTracer

#endif /* !PARSER_HPP_ */
