/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:46:16 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:13:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Character.hpp>

Character::Character(const std::string& name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
	{
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
	{
        name = other.name;
        for (int i = 0; i < 4; i++)
		{
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << "Character assignment operator called" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(A_Materia* tm)
{
    for (int i = 0; i < 4; i++)
	{
        if (!inventory[i])
		{
            inventory[i] = tm;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = NULL;
}

void Character::use(int idx, I_Character& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
