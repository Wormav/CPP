/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:34:59 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/19 00:40:10 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <Weapon.hpp>
#include <iostream>

class HumanA
{
	private:
    	std::string name;
    	Weapon& weapon;

	public:
    	HumanA(std::string name, Weapon& weapon);
    	void attack();
};

#endif
