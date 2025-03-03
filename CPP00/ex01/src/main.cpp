/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:01:33 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/03 20:54:04 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD" || command == "add")
			phoneBook.addContact();
		else if (command == "SEARCH" || command == "search")
			phoneBook.searchContact();
		else if (command == "EXIT" || command == "exit")
			break;
		else if (!command.empty())
			std::cerr << "command not found!" << std::endl;
	}
	return (0);
}
