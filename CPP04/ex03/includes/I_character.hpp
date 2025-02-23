/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I_Character.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:41:22 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:05:44 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_Character_HPP
#define I_Character_HPP

#include <iostream>

class A_Materia;

class I_Character
{
	public:
		virtual ~I_Character() {};
		virtual std::string const & getName() const = 0;
		virtual void equip(A_Materia* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, I_Character& target) = 0;
};

#endif
