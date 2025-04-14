/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:49:14 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:32:45 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
	private:
		std::ifstream					_CSVfile;
		std::ifstream					_inputFile;
		std::map<std::string, float>	_dataBase;

	public:
		BitcoinExchange(const char *inputFile);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(const BitcoinExchange &assign);

		void									readCSV(void);
		void									printValues(void);
		bool									checkFormat(std::string line);
		bool									checkValue(float value);
		std::map<std::string, float>::iterator	findNearestDate(std::string date);
};


#endif
