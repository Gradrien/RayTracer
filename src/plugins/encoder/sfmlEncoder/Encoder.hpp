/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Encoder
*/

#ifndef ENCODER_HPP_
#define ENCODER_HPP_
#include "Color.hpp"
#include "IEncoder.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#define FRAME_RATE_LIMIT 60
#define MAX_VALUE 255
#define BYTE_OF_RGBA_FORMAT 4
#define HEADER_MAGIC_NUMBER "P3"

namespace RayTracer {
/**
 * @class Encoder
 * @brief Encoder class
 */
class SfmlEncoder : public IEncoder {
  public:
    SfmlEncoder() = default;
    ~SfmlEncoder() override = default;
    /**
     * @brief Encode the output into a ppm image
     *
     * @param result_
     * @param filename
     */
    void encodeOutput(std::vector<std::vector<Color>> result_,
        const std::string& filename) override;
    /**
     * @brief Clear the window
     *
     */
    void clearWindow();
    /**
     * @brief Render the window
     *
     */
    void renderWindow();
    /**
     * @brief Set the Frame Rate Limit object
     *
     */
    void setFrameRateLimit();
    /**
     * @brief Draw the image
     *
     * @param filename
     */
    sf::Image loadImage(std::vector<std::vector<Color>> result);
    /**
     * @brief  Display the image
     *
     * @param filename
     */
    void displaySfml(std::vector<std::vector<Color>> result);
    /**
     * @brief Create a Window object
     *
     */
    void createWindow(const std::string& name);
    /**
     * @brief Close the window
     *
     */
    void closeWindow();

    void openSupport(const std::string& name, imageSize size) override;

    bool canClose() override;

    void checkEvents() override;

  private:
    struct Image {
        sf::Texture texture;
        sf::Sprite sprite;
    };
    /**
     * @brief Magic number (P3) indicates that the colors are in ASCII
     * and are in RGB format
     */
    std::string magicNumber_ { HEADER_MAGIC_NUMBER "\n" };
    /**
     * @brief Maximum value of a color
     *
     */
    unsigned int maxValue_ { MAX_VALUE };
    /**
     * @brief Result of the raytracer calculations
     *
     */
    std::vector<std::vector<Color>> result_;

    sf::RenderWindow window_;
    long unsigned int width_;
    long unsigned int height_;
    unsigned int frameRateLimit_ { FRAME_RATE_LIMIT };
    bool canClose_ { false };
};
}
#endif /* !ENCODER_HPP_ */
