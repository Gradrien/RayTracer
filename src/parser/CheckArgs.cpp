/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CheckArgs
*/

#include <string.h>
#include <iostream>
#include <fcntl.h>
#include "Error.hpp"

void displayUsage()
{
    std::cout << "USAGE: ./raytracer  <SCENE_FILE>" << std::endl << std::endl;
    std::cout << "  SCENE_FILE: scene configuration" << std::endl;
}

int checkArgs(int ac, const char *av[])
{
    if (ac != 2 || !av || !av[1]) {
        displayUsage();
        return EPITECH_ERROR;
    }
    if (strcmp(av[1], "--help") == 0 || strcmp(av[1], "-h") == 0) {
        displayUsage();
        return 0;
    }
    return 1;
}
