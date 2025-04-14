/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:49:11 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:32:20 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <regex.h>

BitcoinExchange::BitcoinExchange(const char *fileName):
	_CSVfile("data.csv"),
	_inputFile(fileName)
{
	if (!_CSVfile.is_open() || !_inputFile.is_open())
	{
		throw std::runtime_error("Open failed.");
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (_CSVfile.is_open())
	{
		_CSVfile.close();
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void)assign;

	return (*this);
}

void BitcoinExchange::readCSV(void)
{
    std::string line;

	std::getline(_CSVfile, line);
    while (std::getline(_CSVfile, line))
	{
		std::string key, value;
		std::size_t pos = line.find(',');

		key = line.substr(0, pos);
		value = line.substr(pos + 1);
		_dataBase[key] = strtof(value.c_str(), NULL);
    }
}

bool BitcoinExchange::checkFormat(std::string line)
{
	regex_t regex;
	memset(&regex, 0, sizeof(regex));
	const char *pattern;
	pattern = "^([0-9][0-9][0-9][0-9])-(0[1-9]|1[0-2])-(0[1-9]|1[0-9]|2[0-9])|"
			  "^([0-9][0-9][0-9][0-9])-(0[13-9]|1[0-2])-30|"
			  "^([0-9][0-9][0-9][0-9])-(0[13578]|1[02])-31$"
			  " \\| [+-]?([0-9]+(\\.[0-9]*)?)([eE][+-]?[0-9]+)?$";

	regcomp(&regex, pattern, REG_EXTENDED);
	int error = regexec(&regex, line.c_str(), 0, NULL, 0);
	regfree(&regex);

	if (!error && line.substr(5) == "02-29")
	{
		int year = atoi(line.substr(0, 4).c_str());
		error = !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

	if (error)
	{
		std::cerr << "Error : bad input => " << line << std::endl;
	}

	return (error ? false : true);
}

bool BitcoinExchange::checkValue(float value)
{
	if (value < 0)
	{
		std::cerr << "Error : not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cerr << "Error : too large number." << std::endl;
		return (false);
	}

	return (true);
}

std::map<std::string, float>::iterator BitcoinExchange::findNearestDate(std::string date)
{
	std::map<std::string, float>::iterator it = _dataBase.upper_bound(date);

    if (it != _dataBase.begin())
    {
        it--;
    }

    return (it);
}

void BitcoinExchange::printValues(void)
{
	std::string line;

	std::getline(_inputFile, line);
	while (std::getline(_inputFile, line))
	{
		if (!checkFormat(line))
		{
			continue ;
		}

		std::size_t pos = line.find(" | ");
		std::string date = line.substr(0, pos);
		float value = strtof(line.substr(pos + 3).c_str(), NULL);

		if (!checkValue(value))
		{
			continue ;
		}
		else
		{
			std::map<std::string, float>::iterator it = findNearestDate(date);
			float amount = value * it->second;

			std::cout << date << " => " << value << " = " << amount << std::endl;
		}
	}
}
