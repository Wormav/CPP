/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:36:15 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/19 00:41:01 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <HumanA.hpp>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
