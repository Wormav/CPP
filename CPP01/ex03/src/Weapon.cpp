/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:51:45 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/18 16:58:57 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>

Weapon::Weapon(std::string type) : type(type){}

Weapon::~Weapon(void){}

std::string& Weapon::getType(void)
{
	return this->type;
}
void Weapon::setType(std::string type)
{
	this->type = type;
}
