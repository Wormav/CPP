/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:43:56 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:45:05 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <I_Character.hpp>
#include <A_Materia.hpp>

class Character : public I_Character
{
	private:
		std::string name;
		A_Materia* inventory[4];

	public:
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();

		std::string const & getName() const;
		void equip(A_Materia* m);
		void unequip(int idx);
		void use(int idx, I_Character& target);
	};

#endif
