/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:49:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 13:28:49 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        static void convertChar(const std::string& literal);
        static void convertInt(const std::string& literal);
        static void convertFloat(const std::string& literal);
        static void convertDouble(const std::string& literal);
        static void handleSpecialValues(const std::string& literal);
        static void printResults(char c, int i, float f, double d,
                                bool charValid, bool intValid,
                                bool floatValid, bool doubleValid);

    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

        static void convert(const std::string& literal);
};

#endif
