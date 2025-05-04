/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:11:34 by jlorette          #+#    #+#             */
/*   Updated: 2025/05/04 14:37:50 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <swap.hpp>
#include <min.hpp>
#include <max.hpp>
#include <iostream>
#include <string>

int main()
{
	std::cout << "\n=== Testing with integers ===" << std::endl;
	int a = 42;
	int b = 21;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << "\n=== Testing with floating points ===" << std::endl;
	float f1 = 3.14f;
	float f2 = 2.718f;
	std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
	::swap(f1, f2);
	std::cout << "After swap:  f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;

	std::cout << "\n=== Testing with strings ===" << std::endl;
	std::string str1 = "Hello";
	std::string str2 = "World";
	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	::swap(str1, str2);
	std::cout << "After swap:  str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min(str1, str2) = " << ::min(str1, str2) << std::endl;
	std::cout << "max(str1, str2) = " << ::max(str1, str2) << std::endl;

	std::cout << "\n=== Testing with equal values ===" << std::endl;
	int x = 100;
	int y = 100;
	std::cout << "Equal values: x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	return 0;
}
// subject main

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }
