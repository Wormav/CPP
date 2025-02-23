/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:52:23 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:53:34 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <I_MateriaSource.hpp>
#include <A_Materia.hpp>

class MateriaSource : public I_MateriaSource
{
	private:
		A_Materia* inventory[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource();

		void learnMateria(A_Materia* m);
		A_Materia* createMateria(std::string const & type);
};

#endif
