/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:52:01 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:21:17 by jlorette         ###   ########.fr       */
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

    for (int i = 0; i < numA_Animals / 2; ++i) {
        A_Animals[i] = new Dog();
    }

    std::cout << "\n--- [ Constructors CATS] ---\n" << std::endl;

    for (int i = numA_Animals / 2; i < numA_Animals; ++i) {
        A_Animals[i] = new Cat();
    }

    std::cout << "\n--- [ Destructors ] ---\n" << std::endl;

    for (int i = 0; i < numA_Animals; ++i) {
        delete A_Animals[i];
    }

    // Tentative de créer un objet de type A_Animal
    // A_Animal* abstractAnimal = new A_Animal(); // Cette ligne doit provoquer une erreur de compilation

    return (0);
}
