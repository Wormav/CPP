/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:38:03 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/27 14:39:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

int main()
{
	std::cout << "\n=== Testing with integers ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original array: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with strings ===" << std::endl;
	std::string stringArray[] = {"Hello", "World", "!", "CPP", "Templates"};
	std::cout << "Original array: ";
	iter(stringArray, 5, print<std::string>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with floating points ===" << std::endl;
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::cout << "Original array: ";
	iter(floatArray, 5, print<float>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with characters ===" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Original array: ";
	iter(charArray, 5, print<char>);
	std::cout << std::endl;

	std::cout << "\n=== Testing with partial array ===" << std::endl;
	std::cout << "First 3 elements of int array: ";
	iter(intArray, 3, print<int>);
	std::cout << std::endl;

	return 0;
}
