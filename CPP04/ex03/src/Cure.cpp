/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:39:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:40:26 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cure.hpp>
#include <I_Character.hpp>

Cure::Cure() : A_Materia("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : A_Materia(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
	{
        A_Materia::operator=(other);
    }
    std::cout << "Cure assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

A_Materia* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(I_Character& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
