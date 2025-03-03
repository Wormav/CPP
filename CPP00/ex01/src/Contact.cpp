/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:30:50 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/03 20:34:55 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

std::string Contact::truncate(std::string str) const
{
    if (str.length() > 10)
        return (str.substr(0, 7) + "...");
    return (str);
}

void Contact::setContact(std::string first, std::string last, std::string nick,
                         std::string phone, std::string secret)
{
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::displayFull() const
{
    std::cout << "First Name: " << firstName << "\n"
              << "Last Name: " << lastName << "\n"
              << "Nickname: " << nickname << "\n"
              << "Phone Number: " << phoneNumber << "\n"
              << "Darkest Secret: " << darkestSecret << "\n";
}

void Contact::displayBrief(int index) const
{
    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << truncate(firstName)
              << "|" << std::setw(10) << truncate(lastName)
              << "|" << std::setw(10) << truncate(nickname)
              << "|" << std::endl;
}
