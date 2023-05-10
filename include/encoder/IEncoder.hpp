/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** IEncoder
*/

#ifndef RAYTRACER_IENCODER_HPP
#define RAYTRACER_IENCODER_HPP

#include "Color.hpp"
#include "Size.hpp"
#include <string>
#include <vector>

namespace RayTracer {
class IEncoder {
  public:
    virtual ~IEncoder() = default;
    /**
     * @brief Encodes and saves the rendering result to an output file
     *
     * @param result The rendering result as a 2D vector of colors
     * @param filename The filename of the output file
     */
    virtual void encodeOutput(
        std::vector<std::vector<Color>> result, const std::string& filename)
        = 0;
    /**
     * @brief Opens the necessary support for encoding
     *
     * @param name The name of the support to be opened
     * @param size The size of the image to be encoded
     */
    virtual void openSupport(const std::string& name, imageSize size) = 0;
    /**
     * @brief Checks if the encoder can be closed
     *
     * @return True if the encoder can be closed, False otherwise
     */
    virtual bool canClose() = 0;
    /**
     * @brief Checks for any pending events or actions
     */
    virtual void checkEvents() = 0;
};
} // namespace RayTracer

#endif // RAYTRACER_IENCODER_HPP
