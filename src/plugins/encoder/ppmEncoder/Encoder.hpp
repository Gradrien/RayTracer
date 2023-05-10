/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Encoder
*/

#ifndef ENCODER_HPP_
#define ENCODER_HPP_
#include "IEncoder.hpp"
#include <string>

namespace RayTracer {
/**
 * @class Encoder
 * @brief Encoder class
 */
class Encoder : public IEncoder {
  public:
    Encoder() = default;
    ~Encoder() = default;
    /**
     * @brief
     *
     * @param result_
     * @param filename
     */
    void encodeOutput(std::vector<std::vector<Color>> result_,
        const std::string& filename) override;
    /**
     * @brief
     *
     * @param ofs
     * @param width
     * @param height
     */
    void writeHeaderToPpm(
        std::ofstream& ofs, long unsigned int width, long unsigned int height);
    /**
     * @brief
     *
     * @param ofs
     * @param result_
     */
    void writePixelDataToPpm(
        std::ofstream& ofs, const std::vector<std::vector<Color>>& result_);

    void openSupport(const std::string& name, imageSize size) override;

    bool canClose() override;

    void checkEvents() override;

  private:
    std::vector<std::vector<Color>> result_;
    bool canClose_ { true };
};
}
#endif /* !ENCODER_HPP_ */
