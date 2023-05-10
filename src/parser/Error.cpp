/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Error
*/

#include "Error.hpp"

ParsingError::ParsingError(const char *msg) : msg_{msg}
{
}

const char* ParsingError::what() const noexcept
{
    return this->msg_;
}
