/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:33:56 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 11:04:26 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <A_Materia.hpp>
#include <I_Character.hpp>

class Ice : public A_Materia
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		virtual ~Ice();

		A_Materia* clone() const;
		void use(I_Character& target);
};

#endif
