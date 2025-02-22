/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:52:01 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/22 15:31:53 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

	std::cout << "\n--- [ Constructors Dogs] ---\n" << std::endl;

    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }

	std::cout << "\n--- [ Constructors CATS] ---\n" << std::endl;

    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

	std::cout << "\n--- [ Destructors ] ---\n" << std::endl;

    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return (0);
}
