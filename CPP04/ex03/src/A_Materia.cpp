/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Materia.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:30:47 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:08:31 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <A_Materia.hpp>


A_Materia::A_Materia(const std::string& type) : type(type)
{
    std::cout << "A_Materia constructor called" << std::endl;
}

A_Materia::A_Materia(const A_Materia& other) : type(other.type)
{
    std::cout << "A_Materia copy constructor called" << std::endl;
}

A_Materia& A_Materia::operator=(const A_Materia& other)
{
    if (this != &other)
	{
        type = other.type;
    }
    std::cout << "A_Materia assignment operator called" << std::endl;
    return (*this);
}

A_Materia::~A_Materia()
{
    std::cout << "A_Materia destructor called" << std::endl;
}

std::string const & A_Materia::getType() const
{
    return (type);
}

void A_Materia::use(I_Character& target)
{
    std::cout << "A_Materia used on " << target.getName() << std::endl;
}
