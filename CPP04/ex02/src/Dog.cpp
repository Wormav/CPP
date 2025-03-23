/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:42:24 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 12:57:08 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog() : A_Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called 🐶" << std::endl;
}

Dog::Dog(const Dog& other) : A_Animal(other)
{
    std::cout << "Dog copy constructor called 🐶" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called 🐶" << std::endl;
    if (this != &other)
	{
        A_Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called 🐶" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    if (this->brain)
        this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    if (this->brain)
        return this->brain->getIdea(index);
    return "";
}
