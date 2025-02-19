/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:32:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/19 14:53:28 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name("Default")
{
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap Default is born with a different message! 🐣"
	<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)
{
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << name
	<< " is born with a different message! 🐣" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "DiamondTrap " << name << " is copied! 👨‍❤️‍👨" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap " << name << " is assigned! 🆗" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name
	<< " is destroyed with a different message! 💥" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}
