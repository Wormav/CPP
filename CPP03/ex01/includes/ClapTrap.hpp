/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:14:28 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/18 21:48:10 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string     name;
    unsigned int    hitPoints;
    unsigned int    energyPoints;
    unsigned int    attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setHitPoints(unsigned int hp) { hitPoints = hp; }
    void setEnergyPoints(unsigned int ep) { energyPoints = ep; }
    void setAttackDamage(unsigned int ad) { attackDamage = ad; }
};

#endif
