/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:36:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/19 10:42:24 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap Default is born! 🐣" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << name << " is born! 🐣" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << getName() << " is copied! 👨‍❤️‍👨"
	<< std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << getName() << " is assigned! 🆗" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " is destroyed! 💥" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
	{
        std::cout << "ScavTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage! 🤜"
		<< std::endl;

        setEnergyPoints(getEnergyPoints() - 1);
    }
	else
	{
        std::cout << "ScavTrap " << getName() << " is too weak to attack! 😴"
		<< std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName()
	<< " is now in Gate keeper mode. 👮‍♂️" << std::endl;
}
