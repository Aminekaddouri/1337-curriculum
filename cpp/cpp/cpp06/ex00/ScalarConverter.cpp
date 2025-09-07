/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:25:19 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/30 18:52:40 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib> // for std::strtol, std::strtof, std::strtod
#include <iomanip> // for std::setprecision

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

// Helper function to check if the string is a single character literal
bool isCharLiteral(const std::string& str)
{
    return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

// Detect if the string is a pseudo literal
bool isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

void printCharConversion(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void printIntConversion(double value)
{
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloatConversion(double value)
{
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (value == std::numeric_limits<float>::infinity())
        std::cout << "float: +inff" << std::endl;
    else if (value == -std::numeric_limits<float>::infinity())
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void printDoubleConversion(double value)
{
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (value == std::numeric_limits<double>::infinity())
        std::cout << "double: +inf" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    double value = 0.0;
    
    if (isCharLiteral(literal))
        value  = static_cast<double>(literal[0]);
    else if (isPseudoLiteral(literal))
    {
        if (literal == "nanf" || literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inff" || literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inff" || literal == "-inf")
            value = -std::numeric_limits<double>::infinity();
    }
    else
    {
        char *end;
        value = std::strtod(literal.c_str(), &end);
        if (*end == 'f' && *(end + 1) != '\0')
        {
            std::cout << "Invalid literal." << std::endl;
            return;
        }
        if (*end && *end != 'f')
        {
            std::cout << "Invalid literal." << std::endl;
            return ;
        }
    }

    printCharConversion(value);
    printIntConversion(value);
    printFloatConversion(value);
    printDoubleConversion(value);
}