/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Encoder
*/

#include "Encoder.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace RayTracer {

void Encoder::encodeOutput(
    std::vector<std::vector<Color>> result_, const std::string& filename)
{
    try {
        std::ofstream ofs(filename, std::ios::binary);
        if (!ofs.is_open()) {
            throw std::runtime_error(
                "Error: Failed to open file " + filename + " for writing");
        }

        long unsigned int width = result_[0].size();
        long unsigned int height = result_.size();

        // write header in ppm image
        writeHeaderToPpm(ofs, width, height);

        // write pixel data in ppm image
        writePixelDataToPpm(ofs, result_);

        ofs.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Encoder::writeHeaderToPpm(
    std::ofstream& ofs, long unsigned int width, long unsigned int height)
{
    ofs << "P3\n" << width << " " << height << "\n255\n";
}

void Encoder::writePixelDataToPpm(
    std::ofstream& ofs, const std::vector<std::vector<Color>>& result_)
{
    for (const std::vector<Color>& img : result_) {
        for (Color pixel : img) {
            ofs << pixel.getR() << " " << pixel.getG() << " " << pixel.getB()
                << "\n";
        }
    }
}

void Encoder::openSupport(const std::string& name, imageSize size) { return; }

bool Encoder::canClose() { return this->canClose_; }

void Encoder::checkEvents() { return; }
} // namespace RayTracer
