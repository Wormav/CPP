/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:31:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/03 20:53:33 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
    this->count = 0;
}

void PhoneBook::addContact()
{
    std::string first, last, nick, phone, secret;
    try
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first);
        if (first.empty())
            throw std::runtime_error("First name cannot be empty");

        std::cout << "Enter the name: ";
        std::getline(std::cin, last);
        if (last.empty())
            throw std::runtime_error("Name cannot be empty");

        std::cout << "Enter nickname: ";
        std::getline(std::cin, nick);
        if (nick.empty())
            throw std::runtime_error("Nickname cannot be empty");

        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone);
        if (phone.empty())
            throw std::runtime_error("The number cannot be empty");

        std::cout << "Enter the secret: ";
        std::getline(std::cin, secret);
        if (secret.empty())
            throw std::runtime_error("The secret cannot be empty");

        contacts[count % 8].setContact(first, last, nick, phone, secret);
        count++;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (count == 0)
    {
        std::cout << "No contacts saved" << std::endl;
        return;
    }
    std::cout << "\n|     Index|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < count && i < 8; i++)
        contacts[i].displayBrief(i);

    std::string input;
    std::cout << "Enter contact index: ";
    std::getline(std::cin, input);
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            std::cerr << "Error: index must be a number" << std::endl;
            return;
        }
    }
    int index = std::atoi(input.c_str());
    if (index < 0 || index >= count || index >= 8)
    {
        std::cerr << "Error: invalid index" << std::endl;
        return;
    }
    contacts[index].displayFull();
}
