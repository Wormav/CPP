/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:58:23 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/15 14:57:41 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
   *this = cpy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

bool ScalarConverter::printSpecialCases(const std::string& convert) {
	if (convert == "nan" || convert == "nanf") {
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return true;
	}
	if (convert == "+inf" || convert == "+inff" || convert == "inf" || convert == "inff") {
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
		return true;
	}
	if (convert == "-inf" || convert == "-inff") {
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: \'" << c << "\'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(long int i) {
	if (i < 0 || i > 127)
		std::cout << "char: impossible\n";
	else if (i < 32 || i > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: \'" << static_cast<char>(i) << "\'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "char: ";
	if (f >= 0 && f <= 127 && (static_cast<int>(f) >= 32 && static_cast<int>(f) <= 126))
		std::cout << "'" << static_cast<char>(f) << "'\n";
	else if (f < 0 || f > 127)
		std::cout << "impossible\n";
	else if (f < ' ' || f > '~')
		std::cout << "Non displayable\n";
	else
		std::cout << "impossible\n";

	std::cout << "int: ";
	if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
		std::cout << static_cast<int>(f) << "\n";
	else
		std::cout << "impossible\n";

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "char: ";
	if (d >= 0 && d <= 127 && (static_cast<int>(d) >= 32 && static_cast<int>(d) <= 126))
		std::cout << "'" << static_cast<char>(d) << "'\n";
	else if (d < 0 || d > 127)
		std::cout << "impossible\n";
	else if (d < ' ' || d > '~')
		std::cout << "Non displayable\n";
	else
		std::cout << "impossible\n";

	std::cout << "int: ";
	if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
		std::cout << static_cast<int>(d) << "\n";
	else
		std::cout << "impossible\n";

	std::cout << "float: ";
	if (d > FLT_MAX)
		std::cout << "+inff\n";
	else if (d < -FLT_MAX)
		std::cout << "-inff\n";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";

	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printImpossible() {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string convert) {
	char *end;
	int len_convert = convert.length();

	if (printSpecialCases(convert))
		return;

	if (len_convert == 1 && (convert[0] >= 32 && convert[0] <= 126) && !(convert[0] >= '0' && convert[0] <= '9')) {
		printChar(convert[0]);
		return;
	}

	long int i = std::strtol(convert.c_str(), &end, 10);
	if (*end == '\0' && i >= INT_MIN && i <= INT_MAX) {
		printInt(i);
		return;
	}


	size_t point_pos = convert.find('.');
	size_t f_pos = convert.find('f');
	if (point_pos != std::string::npos && f_pos != std::string::npos && f_pos > point_pos) {
		try {
			float f = std::strtof(convert.c_str(), &end);
			if (*end != 'f') {
				printImpossible();
				return;
			}
			if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max()) {
				printImpossible();
				return;
			}
			printFloat(f);
			return;
		} catch (...) {
			printImpossible();
			return;
		}
	}

	try {
		double d = std::strtod(convert.c_str(), &end);
		if (*end != '\0') {
			printImpossible();
			return;
		}
		if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max()) {
			printImpossible();
			return;
		}
		printDouble(d);
		return;
	} catch (...) {
		printImpossible();
		return;
	}

	printImpossible();
}
