/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:53:51 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:15:49 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MateriaSource.hpp>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
	{
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
 {
    if (this != &other)
	{
        for (int i = 0; i < 4; i++)
		{
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << "MateriaSource assignment operator called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(A_Materia* m)
{
    for (int i = 0; i < 4; i++)
	{
        if (!inventory[i])
		{
            inventory[i] = m;
            break ;
        }
    }
}

A_Materia* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
	{
        if (inventory[i] && inventory[i]->getType() == type)
            return inventory[i]->clone();
    }
    return (NULL);
}
