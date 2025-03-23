/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:52:01 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 12:45:27 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main()
{
	const int numAnimals = 10;
	Animal* animals[numAnimals];

	std::cout << "\n--- [ Constructors Dogs] ---\n" << std::endl;

	for (int i = 0; i < numAnimals / 2; ++i)
		animals[i] = new Dog();

	std::cout << "\n--- [ Constructors CATS] ---\n" << std::endl;

	for (int i = numAnimals / 2; i < numAnimals; ++i)
		animals[i] = new Cat();

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

	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];

	return (0);
}
