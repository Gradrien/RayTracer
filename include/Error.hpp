/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Error
*/

/****************************************************************
 * @file Error.hpp
 * @brief Error class
 * @details This class is used to handle the errors
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <exception>
#include <iostream>

#define EPITECH_ERROR 84
/****************************************************************
 * @brief Error class
 * @details This class is used to handle the errors
 * *************************************************************/
class ParsingError : public std::exception {
  public:
    /****************************************************************
     * @brief Construct a new Parsing Error object
     * @param msg
     * @details This function is used to construct the error
     * ************************************************/
    ParsingError(const char* msg);
    ~ParsingError() override = default;
    /****************************************************************
     * @brief Get the What object
     * @return const char*
     * @details This function is used to get the what
     * ************************************************/
    const char* what() const noexcept override;

  private:
    const char* msg_;
};

#endif /* !ERROR_HPP_ */
