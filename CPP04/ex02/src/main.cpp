/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:52:01 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 13:00:17 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <A_Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main()
{
	const int numA_Animals = 10;
	A_Animal* A_Animals[numA_Animals];

	std::cout << "\n--- [ Constructors Dogs] ---\n" << std::endl;

	for (int i = 0; i < numA_Animals / 2; ++i)
		A_Animals[i] = new Dog();

	std::cout << "\n--- [ Constructors CATS] ---\n" << std::endl;

	for (int i = numA_Animals / 2; i < numA_Animals; ++i)
		A_Animals[i] = new Cat();

	std::cout << "\n--- [ Deep copy test - Dog ] ---\n" << std::endl;
	{
		Dog basicDog;
		basicDog.setIdea(0, "I want to eat a bone");

		Dog copyDog = basicDog;

		std::cout << "Original idea of basicDog: " << basicDog.getIdea(0) << std::endl;
		std::cout << "Copied idea in copyDog: " << copyDog.getIdea(0) << std::endl;

		copyDog.setIdea(0, "I want to chase my tail");
		std::cout << "After modification, basicDog idea: " << basicDog.getIdea(0) << std::endl;
		std::cout << "After modification, copyDog idea: " << copyDog.getIdea(0) << std::endl;

	}
	std::cout << "basicDog still exists and its Brain hasn't been deleted\n" << std::endl;

	std::cout << "\n--- [ Assignment operator test - Cat ] ---\n" << std::endl;
	{
		Cat cat1;
		cat1.setIdea(0, "I want a mouse");

		Cat cat2;
		cat2.setIdea(0, "I want to sleep");

		std::cout << "Before assignment - cat1 idea: " << cat1.getIdea(0) << std::endl;
		std::cout << "Before assignment - cat2 idea: " << cat2.getIdea(0) << std::endl;

		cat1 = cat2;

		std::cout << "After assignment - cat1 idea: " << cat1.getIdea(0) << std::endl;
		std::cout << "After assignment - cat2 idea: " << cat2.getIdea(0) << std::endl;

		cat2.setIdea(0, "I want to play with wool");
		std::cout << "After modification - cat1 idea: " << cat1.getIdea(0) << std::endl;
		std::cout << "After modification - cat2 idea: " << cat2.getIdea(0) << std::endl;
	}

	std::cout << "\n--- [ Destructors ] ---\n" << std::endl;

	for (int i = 0; i < numA_Animals; ++i)
		delete A_Animals[i];

			// Attempt to create an A_Animal object
			// A_Animal* abstractA_Animal = new A_Animal(); // This line should cause a compilation error


    return (0);
}
