/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:36:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/18 21:46:55 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap Default is born!" << std::endl;
}
