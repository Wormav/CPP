/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:42:24 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:18:20 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called 🐶" << std::endl;
}

Dog::Dog(const Dog& other) : A_Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor called 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
	{
        A_Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
    }
    std::cout << "Dog assignment operator called 🐶" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called 🐶" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! 🐶" << std::endl;
}
