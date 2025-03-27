/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:42:17 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/27 14:50:01 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>

class Array
{
	private:
		T *elements;
		unsigned int n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);

		T &operator[](unsigned int index);
		unsigned int size() const;
};

#include "Array.tpp"

#endif
