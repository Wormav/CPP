/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:54:13 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:30:54 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <iostream>

int main()
{
	std::cout << "[Converting '0']" << std::endl << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl << "[Converting nan]" << std::endl << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl << "[Converting 42.0f]" << std::endl << std::endl;
	ScalarConverter::convert("42.0f");
	return 0;
}
