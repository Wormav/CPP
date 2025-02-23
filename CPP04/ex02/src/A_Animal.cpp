/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:29:36 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:12:14 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <A_Animal.hpp>

A_Animal::A_Animal() : type("A_Animal")
{
    std::cout << "A_Animal constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other) : type(other.type)
{
    std::cout << "A_Animal copy constructor called" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& other)
{
    if (this != &other)
	{
        type = other.type;
    }
    std::cout << "A_Animal assignment operator called" << std::endl;
    return (*this);
}

A_Animal::~A_Animal()
{
    std::cout << "A_Animal destructor called" << std::endl;
}

std::string A_Animal::getType() const
{
    return (type);
}
