/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Encoder
*/

#include "Encoder.hpp"
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace RayTracer {

void SfmlEncoder::encodeOutput(
    std::vector<std::vector<Color>> result, const std::string& filename)
{
    try {
        displaySfml(result);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

sf::Image SfmlEncoder::loadImage(std::vector<std::vector<Color>> result)
{
    this->width_ = result[0].size();
    this->height_ = result.size();

    // Allocate memory for the image data
    std::vector<unsigned char> data(
        this->width_ * this->height_ * BYTE_OF_RGBA_FORMAT);

    // Read the pixel data from the PPM file
    int pixelIndex = 0;
    for (int y = 0; y < this->height_; y++) {
        for (int x = 0; x < this->width_; x++) {
            data[pixelIndex++] = result[y][x].getR();
            data[pixelIndex++] = result[y][x].getG();
            data[pixelIndex++] = result[y][x].getB();
            data[pixelIndex++] = this->maxValue_;
        }
    }

    // Create an SFML image from the pixel data and return it
    sf::Image image;
    image.create(this->width_, this->height_, data.data());

    return image;
}

void SfmlEncoder::displaySfml(std::vector<std::vector<Color>> result)
{

    // Load the ppm image and create an SFML texture
    sf::Image image = loadImage(result);
    sf::Texture texture;
    texture.loadFromImage(image);

    // Create an SFML sprite and set its texture
    sf::Sprite sprite(texture);

    if (this->window_.isOpen()) {
        sf::Event event;
        while (this->window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window_.close();
            }
        }

        this->window_.clear();
        this->window_.draw(sprite);
        this->window_.display();
    }
}

void SfmlEncoder::createWindow(const std::string& name)
{
    this->window_.create(
        sf::VideoMode { static_cast<unsigned int>(this->width_),
            static_cast<unsigned int>(this->height_) },
        name);
}

void SfmlEncoder::setFrameRateLimit()
{
    this->window_.setFramerateLimit(this->frameRateLimit_);
}

void SfmlEncoder::clearWindow() { this->window_.clear(); }

void SfmlEncoder::renderWindow() { this->window_.display(); }

void SfmlEncoder::closeWindow()
{
    this->window_.close();
    this->canClose_ = true;
}

void SfmlEncoder::openSupport(const std::string& name, imageSize size)
{
    this->width_ = size.width;
    this->height_ = size.height;
    this->createWindow(name);
    setFrameRateLimit();
}

bool SfmlEncoder::canClose() { return this->canClose_; }

void SfmlEncoder::checkEvents()
{
    if (this->window_.isOpen()) {
        sf::Event event;
        while (this->window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window_.close();
                this->canClose_ = true;
            }
        }
    }
}

} // namespace RayTracer
