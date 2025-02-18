/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:35:34 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/18 21:50:05 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

ClapTrap::ClapTrap() : name("Wormav"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Wormav is born" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap" << name << "is born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " is copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
	{
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " is assigned!" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;

        energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is too weak to attack!"
		<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " takes " << amount
		<< " points of damage!" << std::endl;

		if (hitPoints > 1)
			hitPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << name
		<<  " is already dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
        std::cout << "ClapTrap " << name << " repairs itself, gaining "
		<< amount << " hit points!" << std::endl;

        hitPoints += amount;
        energyPoints--;
    }
	else
	{
        std::cout << "ClapTrap " << name << " is too weak to repair itself!"
		<< std::endl;
    }
}

void ClapTrap::setHitPoints(unsigned int hp)
{
    this->hitPoints = hp;
}

void ClapTrap::setEnergyPoints(unsigned int ep)
{
    this->energyPoints = ep;
}

void ClapTrap::setAttackDamage(unsigned int ad)
{
    this->attackDamage = ad;
}
