/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#ifndef RAYTRACER_CORE_HPP
#define RAYTRACER_CORE_HPP
#include "DLLoader.hpp"
#include "IEncoder.hpp"
#include "IParser.hpp"
#include "IRenderer.hpp"
#include <filesystem>

namespace RayTracer {
class Core {
  public:
    Core() = default;
    ~Core() = default;
    /**
     * Set the renderer for the scene.
     * @param renderer A unique pointer to the IRenderer object.
     */
    void setRenderer(std::unique_ptr<IRenderer> renderer);
    /**
     * Set the parser for the scene.
     * @param parser A unique pointer to the IParser object.
     */
    void setParser(std::unique_ptr<IParser> parser);
    /**
     * Set the encoder for the scene.
     * @param encoder A unique pointer to the IEncoder object.
     */
    void setEncoder(std::unique_ptr<IEncoder> encoder);
    /**
     * Get the renderer of the scene.
     * @return A reference to a unique pointer to the IRenderer object.
     */
    std::unique_ptr<IRenderer>& getRenderer();
    /**
     * Get the encoder of the scene.
     * @return A reference to a unique pointer to the IEncoder object.
     */
    std::unique_ptr<IEncoder>& getEncoder();
    /**
     * Get the parser of the scene.
     * @return A reference to a unique pointer to the IParser object.
     */
    std::unique_ptr<IParser>& getParser();
    /**
     * Load the scene.
     * @exception throw an exception if the scene cannot be loaded
     */
    void loadScene();
    /**
     * Load a parser by its name.
     * @param name A constant reference to the string name of the parser.
     */
    void loadParser(const std::string& name);
    /**
     * Load an encoder by its name.
     * @param name A constant reference to the string name of the encoder.
     */
    void loadEncoder(const std::string& name);
    /**
     * Load a renderer by its name.
     * @param name A constant reference to the string name of the renderer.
     */
    void loadRenderer(const std::string& name);

    /**
     * @brief Starts the command-line interface with the specified
     * configuration.
     *
     * @param config The configuration file to use.
     */
    void startCli(const char* config);

    /**
     * @brief Handles a command received through the command-line interface.
     */
    static void handleCommand();

    /**
     * @brief Handles real-time preview of the scene.
     *
     * @return True if the real-time preview is successfully handled, False
     * otherwise.
     */
    static bool handleRealPreview();

    /**
     * @brief Renders the final image of the scene.
     */
    void renderImage();

    /**
     * @brief Resets the primitives in the scene.
     */
    void resetPrimitives();

  private:
    DLLoader<IEncoder> encoderLoader_;
    DLLoader<IRenderer> rendererLoader_;
    DLLoader<IParser> parserLoader_;
    std::unique_ptr<IRenderer> renderer_ { nullptr };
    std::unique_ptr<IEncoder> encoder_ { nullptr };
    std::unique_ptr<IParser> parser_ { nullptr };
};
} // namespace RayTracer

#endif // RAYTRACER_CORE_HPP
