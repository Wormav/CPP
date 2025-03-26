/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:49:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:37:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

//! voir si obliger faire une form canonique

class ScalarConverter
{
	private:
		ScalarConverter() {}
		static void convertChar(const std::string& literal);
		static void convertInt(const std::string& literal);
		static void convertFloat(const std::string& literal);
		static void convertDouble(const std::string& literal);
		static void printResults(char c, int i, float f, double d);

	public:
		static void convert(const std::string& literal);
};

#endif
