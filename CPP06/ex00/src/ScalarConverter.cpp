/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:51:16 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 13:33:18 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <string>
#include <cctype>
#include <cerrno>

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string& literal)
{
    // Vérifier pour les valeurs spéciales
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff" || literal == "inf" || literal == "inff")
    {
        handleSpecialValues(literal);
        return;
    }

    if (literal.size() == 1 && !std::isdigit(literal[0]))
        convertChar(literal);
    else if (literal.find('.') != std::string::npos || literal.find('e') != std::string::npos)
    {
        if (literal.find('f') != std::string::npos)
            convertFloat(literal);
        else
            convertDouble(literal);
    }
    else
        convertInt(literal);
}

void ScalarConverter::convertChar(const std::string& literal)
{
    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    printResults(c, i, f, d, true, true, true, true);
}

void ScalarConverter::convertInt(const std::string& literal)
{
    char* end;
    errno = 0;
    long value = std::strtol(literal.c_str(), &end, 10);

    bool intPossible = (*end == '\0' && errno == 0 &&
                        value >= std::numeric_limits<int>::min() &&
                        value <= std::numeric_limits<int>::max());

    bool charPossible = (intPossible && value >= 0 && value <= 127);
    bool displayable = (charPossible && std::isprint(static_cast<char>(value)));

    int i = static_cast<int>(value);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printResults(c, i, f, d, displayable, intPossible, true, true);
}

void ScalarConverter::convertFloat(const std::string& literal)
{
    char* end;
    errno = 0;
    float f = std::strtof(literal.c_str(), &end);

    bool floatPossible = ((*end == 'f' && *(end + 1) == '\0') || *end == '\0') && errno == 0;
    bool intPossible = (floatPossible && f >= std::numeric_limits<int>::min() &&
                        f <= std::numeric_limits<int>::max() &&
                        f == static_cast<float>(static_cast<int>(f)));

    int i = static_cast<int>(f);
    char c = static_cast<char>(i);
    double d = static_cast<double>(f);

    bool charPossible = (intPossible && i >= 0 && i <= 127);
    bool displayable = (charPossible && std::isprint(c));

    printResults(c, i, f, d, displayable, intPossible, floatPossible, true);
}

void ScalarConverter::convertDouble(const std::string& literal)
{
    char* end;
    errno = 0;
    double d = std::strtod(literal.c_str(), &end);

    bool doublePossible = (*end == '\0' && errno == 0);
    bool floatPossible = (doublePossible && d >= -std::numeric_limits<float>::max() &&
                         d <= std::numeric_limits<float>::max());
    bool intPossible = (floatPossible && d >= std::numeric_limits<int>::min() &&
                        d <= std::numeric_limits<int>::max() &&
                        d == static_cast<double>(static_cast<int>(d)));

    int i = static_cast<int>(d);
    char c = static_cast<char>(i);
    float f = static_cast<float>(d);

    bool charPossible = (intPossible && i >= 0 && i <= 127);
    bool displayable = (charPossible && std::isprint(c));

    printResults(c, i, f, d, displayable, intPossible, floatPossible, doublePossible);
}

void ScalarConverter::handleSpecialValues(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff") {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::printResults(char c, int i, float f, double d,
                                  bool charValid, bool intValid, bool floatValid, bool doubleValid)
{
    std::cout << "char: ";
    if (!charValid)
        std::cout << "impossible";
    else if (std::isprint(c))
        std::cout << "'" << c << "'";
    else
        std::cout << "Non displayable";
    std::cout << std::endl;

    std::cout << "int: ";
    if (!intValid)
        std::cout << "impossible";
    else
        std::cout << i;
    std::cout << std::endl;

    std::cout << "float: ";
    if (!floatValid)
        std::cout << "impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    std::cout << std::endl;

    std::cout << "double: ";
    if (!doubleValid)
        std::cout << "impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << d;
    std::cout << std::endl;
}
