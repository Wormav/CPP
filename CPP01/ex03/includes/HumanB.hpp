/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:43:40 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 17:11:46 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
    	std::string name;
    	Weapon* weapon;

	public:
    	HumanB(const std::string& name, Weapon* weapon = NULL);
    	void setWeapon(Weapon& weapon);
    	void attack() const;
};

#endif
