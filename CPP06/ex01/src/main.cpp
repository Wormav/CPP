/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:44:50 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:59:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>
#include <Data.hpp>
#include <iostream>

int main()
{
		std::cout << "\n=== Test 1: Basic functionality ===" << std::endl;
		Data data;
		data.setValue(42);

		unsigned long serialized = Serializer::serialize(&data);
		Data* deserialized = Serializer::deserialize(serialized);

		std::cout << "Original address: " << &data << std::endl;
		std::cout << "Deserialized address: " << deserialized << std::endl;
		std::cout << "Original value: " << data.getValue() << std::endl;
		std::cout << "Deserialized value: " << deserialized->getValue() << std::endl;
		std::cout << "Test " << (deserialized == &data ? "PASSED" : "FAILED") << std::endl;

		std::cout << "\n=== Test 2: Multiple objects ===" << std::endl;
		Data data1, data2;
		data1.setValue(100);
		data2.setValue(200);

		unsigned long ser1 = Serializer::serialize(&data1);
		unsigned long ser2 = Serializer::serialize(&data2);

		Data* des1 = Serializer::deserialize(ser1);
		Data* des2 = Serializer::deserialize(ser2);

		std::cout << "Data1 - Original: " << data1.getValue()
				 << ", Deserialized: " << des1->getValue() << std::endl;
		std::cout << "Data2 - Original: " << data2.getValue()
				 << ", Deserialized: " << des2->getValue() << std::endl;

	{
		std::cout << "\n=== Test 3: NULL pointer ===" << std::endl;
		Data* nullPtr = NULL;
		unsigned long serialized = Serializer::serialize(nullPtr);
		Data* deserialized = Serializer::deserialize(serialized);

		std::cout << "Original NULL ptr: " << nullPtr << std::endl;
		std::cout << "Deserialized NULL ptr: " << deserialized << std::endl;
		std::cout << "Test " << (deserialized == nullPtr ? "PASSED" : "FAILED") << std::endl;
	}

	return 0;
}
