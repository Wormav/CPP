/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:54:13 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 12:39:08 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <iostream>

int main()
{
    // base
    std::cout << "[Converting '0']" << std::endl << std::endl;
    ScalarConverter::convert("0");

    std::cout << std::endl << "[Converting nan]" << std::endl << std::endl;
    ScalarConverter::convert("nan");

    std::cout << std::endl << "[Converting 42.0f]" << std::endl << std::endl;
    ScalarConverter::convert("42.0f");

    // Char
    std::cout << std::endl << "[Converting 'a']" << std::endl << std::endl;
    ScalarConverter::convert("a");

    std::cout << std::endl << "[Converting '*']" << std::endl << std::endl;
    ScalarConverter::convert("*");

    // Int
    std::cout << std::endl << "[Converting '42']" << std::endl << std::endl;
    ScalarConverter::convert("42");

    std::cout << std::endl << "[Converting '-42']" << std::endl << std::endl;
    ScalarConverter::convert("-42");

    std::cout << std::endl << "[Converting '2147483647' (INT_MAX)]" << std::endl << std::endl;
    ScalarConverter::convert("2147483647");

    // Float
    std::cout << std::endl << "[Converting '4.2f']" << std::endl << std::endl;
    ScalarConverter::convert("4.2f");

    std::cout << std::endl << "[Converting '-4.2f']" << std::endl << std::endl;
    ScalarConverter::convert("-4.2f");

    // Double
    std::cout << std::endl << "[Converting '4.2']" << std::endl << std::endl;
    ScalarConverter::convert("4.2");

    std::cout << std::endl << "[Converting '-4.2']" << std::endl << std::endl;
    ScalarConverter::convert("-4.2");

    // specials
    std::cout << std::endl << "[Converting 'inf']" << std::endl << std::endl;
    ScalarConverter::convert("inf");

    std::cout << std::endl << "[Converting '-inf']" << std::endl << std::endl;
    ScalarConverter::convert("-inf");

    std::cout << std::endl << "[Converting 'inff']" << std::endl << std::endl;
    ScalarConverter::convert("inff");

    std::cout << std::endl << "[Converting 'nanf']" << std::endl << std::endl;
    ScalarConverter::convert("nanf");

    //limites
    std::cout << std::endl << "[Converting '0.0f']" << std::endl << std::endl;
    ScalarConverter::convert("0.0f");

    std::cout << std::endl << "[Converting '3.402823e+38f' (FLT_MAX)]" << std::endl << std::endl;
    ScalarConverter::convert("3.402823e+38f");

    return 0;
}
