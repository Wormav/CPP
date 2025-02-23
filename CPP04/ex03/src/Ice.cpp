/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:35:24 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:13:51 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Ice.hpp>
#include <I_Character.hpp>

Ice::Ice() : A_Materia("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : A_Materia(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
	{
        A_Materia::operator=(other);
    }
    std::cout << "Ice assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

A_Materia* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(I_Character& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
	<< std::endl;
}
