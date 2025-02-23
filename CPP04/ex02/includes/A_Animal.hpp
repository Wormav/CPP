/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:16:26 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/23 10:12:45 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class A_Animal
{
	protected:
		std::string type;

	public:
		A_Animal();
		A_Animal(const A_Animal& other);
		A_Animal& operator=(const A_Animal& other);
		virtual ~A_Animal();

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
