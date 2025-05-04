/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:38:03 by jlorette          #+#    #+#             */
/*   Updated: 2025/05/04 15:16:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::cout << "\n=== Test with Integer Array ===" << std::endl;
	Array<int> intArray(5);
	std::cout << "Filling array with values..." << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = i * 2;

	std::cout << "Original array: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test Copy Constructor ===" << std::endl;
	Array<int> intArrayCopy = intArray;
	std::cout << "Copied array: ";
	for (unsigned int i = 0; i < intArrayCopy.size(); ++i)
		std::cout << intArrayCopy[i] << " ";
	std::cout << std::endl;

	std::cout << "Modifying original array..." << std::endl;
	intArray[0] = 100;
	std::cout << "Original array: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";

	std::cout << "\nCopied array (should be unchanged): ";
	for (unsigned int i = 0; i < intArrayCopy.size(); ++i)
		std::cout << intArrayCopy[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test with String Array ===" << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	for (unsigned int i = 0; i < stringArray.size(); ++i)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test Exception Handling ===" << std::endl;
	try
	{
		std::cout << "Trying to access index 10..." << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test Default Constructor ===" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

	std::cout << "\n=== Test Assignment Operator ===" << std::endl;
	Array<int> assignArray(2);
	assignArray[0] = 42;
	assignArray[1] = 21;
	intArray = assignArray;
	std::cout << "Array after assignment: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	return 0;
}

// subject main

// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
