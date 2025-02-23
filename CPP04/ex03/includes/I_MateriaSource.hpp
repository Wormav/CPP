/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I_MateriaSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:50:30 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:59:30 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MateriaSource_HPP
#define I_MateriaSource_HPP

#include <A_Materia.hpp>

class I_MateriaSource
{
	public:
		virtual ~I_MateriaSource() {}
		virtual void learnMateria(A_Materia*) = 0;
		virtual A_Materia* createMateria(std::string const & type) = 0;
};

#endif
