/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:50:28 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 12:09:13 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called 🐈" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called 🐈" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat assignment operator called 🐈" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called 🐈" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! 🐈" << std::endl;
}
