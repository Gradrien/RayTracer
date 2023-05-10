/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Main
*/

#include "Camera.hpp"
#include "Core.hpp"
#include "Error.hpp"
#include "Parser.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "Vector3D.hpp"
#include <cfloat>
#include <fstream>
#include <iostream>

int checkArgs(int ac, const char* av[]);

int main(const int ac, const char* av[])
{
    RayTracer::Core core;
    int retargs = checkArgs(ac, av);

    if (retargs != 1)
        return retargs;
    try {
        core.startCli(av[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EPITECH_ERROR;
    }
    return 0;
}
