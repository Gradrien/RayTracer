/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#include "Core.hpp"
#include "Camera.hpp"
#include "Parser.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
void Core::setEncoder(std::unique_ptr<IEncoder> encoder)
{
    this->encoder_ = std::move(encoder);
}

void Core::setParser(std::unique_ptr<IParser> parser)
{
    this->parser_ = std::move(parser);
}

void Core::setRenderer(std::unique_ptr<IRenderer> renderer)
{
    this->renderer_ = std::move(renderer);
}

std::unique_ptr<IEncoder>& Core::getEncoder() { return this->encoder_; }

std::unique_ptr<IParser>& Core::getParser() { return this->parser_; }

std::unique_ptr<IRenderer>& Core::getRenderer() { return this->renderer_; }

void Core::loadScene()
{
    this->parser_->parse(this->renderer_->getScene().getCamera());
    std::cout << "Set cam\n";
    for (std::unique_ptr<RayTracer::IPrimitives>& prim :
        this->parser_->getPrimitives()) {
        this->renderer_->getScene().addPrimitive(std::move(prim));
    }
    for (std::unique_ptr<RayTracer::ILight>& light :
        this->parser_->getLights()) {
        this->renderer_->getScene().addLight(std::move(light));
    }
}

void Core::loadRenderer(const std::string& name)
{
    const std::filesystem::path libPath { "./plugins/renderer" };
    for (auto const& dir_entry :
        std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().stem().c_str()[0] == '.')
            continue;
        if (dir_entry.path().stem().c_str() != name)
            continue;
        this->renderer_ = this->rendererLoader_.getInstance(dir_entry.path());
    }
    if (this->renderer_.get() == nullptr)
        throw ParsingError("Could not load renderer library");
}

void Core::loadParser(const std::string& name)
{
    const std::filesystem::path libPath { "./plugins/parser" };
    for (auto const& dir_entry :
        std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().stem().c_str()[0] == '.')
            continue;
        if (dir_entry.path().stem().c_str() != name)
            continue;
        this->parser_ = this->parserLoader_.getInstance(dir_entry.path());
    }
    if (this->parser_.get() == nullptr)
        throw ParsingError("Could not load parser library");
}

void Core::loadEncoder(const std::string& name)
{
    const std::filesystem::path libPath { "./plugins/encoder" };
    for (auto const& dir_entry :
        std::filesystem::directory_iterator { libPath }) {
        if (dir_entry.path().stem().c_str()[0] == '.')
            continue;
        if (dir_entry.path().stem().c_str() != name)
            continue;
        this->encoder_ = this->encoderLoader_.getInstance(dir_entry.path());
    }
    if (this->encoder_.get() == nullptr)
        throw ParsingError("Could not load encoder library");
}

void Core::handleCommand()
{
    std::string line;
    std::getline(std::cin, line);

    if (line == "exit")
        exit(0);
}

void Core::resetPrimitives()
{
    this->parser_->getPrimitives().clear();
    this->parser_->getLights().clear();
}

void Core::startCli(const char* config)
{
    if (!config)
        return;
    this->setParser(std::make_unique<RayTracer::Parser>(config));
    std::cout << "Parser set\n";
    this->loadEncoder(this->getParser()->getEncoderName());
    std::cout << "Encoder loaded\n";

    if (this->parser_->isFastRendererEnabled()) {
        std::cout << "Generating the preview...\n";
        this->loadRenderer(this->parser_->getFastRendererFileName());
        this->renderImage();
        std::cout << "\nPreview successfully generated !\n";
        if (!handleRealPreview())
            return;
        this->resetPrimitives();
    }
    this->loadRenderer(this->parser_->getRendererName());
    std::cout << "Generating the image...\n";
    this->renderImage();
    std::cout << "\nImage successfully generated !\n";
    while (!this->encoder_->canClose()) {
        this->encoder_->checkEvents();
    }
}

bool Core::handleRealPreview()
{
    std::string line;
    do {
        std::cout << "\nDo you want to render the real image [y/n]: ";
        std::getline(std::cin, line);
    } while (line != "y" && line != "n");
    return line == "y";
}

void Core::renderImage()
{
    this->loadScene();
    this->renderer_->initIterators();
    this->encoder_->openSupport(this->getParser()->getOutputFileName(),
        this->renderer_->getScene().getCamera().imageSize_);
    std::cout << "Computing the scene, please wait...\n";
    std::cout << "$> " << std::flush;
    while (!this->renderer_->isGenerationDone()) {
        this->renderer_->computeScene();
        if (this->renderer_->canWrite()) {
            this->getEncoder()->encodeOutput(this->getRenderer()->getResult(),
                this->getParser()->getOutputFileName());
        }
        if (this->renderer_->isCommand()) {
            this->handleCommand();
            std::cout << "$> " << std::flush;
        }
    }
}
}
