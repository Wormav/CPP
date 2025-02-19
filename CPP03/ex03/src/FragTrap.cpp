/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:53:32 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/19 14:02:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap("Default")
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap Default is born with a different message! 🐣"
	<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << name << " is born with a different message! 🐣"
	<< std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << getName() << " is copied! 👨‍❤️‍👨"
	<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap " << getName() << " is assigned! 🆗" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " is destroyed with a different message! 💥" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << getName() << " requests a high five! 🙌" << std::endl;
}
