/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:51:16 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:28:20 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>


void ScalarConverter::convert(const std::string& literal)
{
    if (literal.size() == 1 && isprint(literal[0]))
        convertChar(literal);
    else if (literal.find('.') != std::string::npos)
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
    printResults(c, i, f, d);
}

void ScalarConverter::convertInt(const std::string& literal)
{
    int i = std::atoi(literal.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printResults(c, i, f, d);
}

void ScalarConverter::convertFloat(const std::string& literal)
{
    float f = std::strtof(literal.c_str(), 0);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);
    printResults(c, i, f, d);
}

void ScalarConverter::convertDouble(const std::string& literal)
{
    double d = std::strtod(literal.c_str(), 0);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    printResults(c, i, f, d);
}

void ScalarConverter::printResults(char c, int i, float f, double d)
{
    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f
	<< "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
	<< d << std::endl;
}
