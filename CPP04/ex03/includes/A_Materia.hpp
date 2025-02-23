/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Materia.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:25:05 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:11:04 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include <I_Character.hpp>

class I_Character;

class A_Materia
{
	protected:
		std::string type;

	public:
		A_Materia(const std::string& type);
		A_Materia(const A_Materia& other);
		A_Materia& operator=(const A_Materia& other);
		virtual ~A_Materia();

		std::string const & getType() const;
		virtual A_Materia* clone() const = 0;
		virtual void use(I_Character& target);
};

#endif
