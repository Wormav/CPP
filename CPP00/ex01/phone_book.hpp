/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:02:19 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/12 17:03:12 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

        std::string truncate(std::string str) const
        {
            if (str.length() > 10)
                return (str.substr(0, 7) + "...");
            return (str);
        }

    public:
        void setContact(std::string first, std::string last, std::string nick,
                std::string phone, std::string secret)
        {
            firstName = first;
            lastName = last;
            nickname = nick;
            phoneNumber = phone;
            darkestSecret = secret;
        }

        void displayFull() const
        {
            std::cout << "First Name: " << firstName << "\n"
                    << "Last Name: " << lastName << "\n"
                    << "Nickname: " << nickname << "\n"
                    << "Phone Number: " << phoneNumber << "\n"
                    << "Darkest Secret: " << darkestSecret << "\n";
        }

        void displayBrief(int index) const
        {
            std::cout << "|" << std::setw(10) << index
                    << "|" << std::setw(10) << truncate(firstName)
                    << "|" << std::setw(10) << truncate(lastName)
                    << "|" << std::setw(10) << truncate(nickname)
                    << "|" << std::endl;
        }
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;

    public:
        PhoneBook()
        {
            this->count = 0;
        }

        void addContact()
        {
            std::string first, last, nick, phone, secret;
            try
            {
                std::cout << "Entrez le prénom: ";
                std::getline(std::cin, first);
                if (first.empty())
                    throw std::runtime_error("Le prénom ne peut pas être vide");

                std::cout << "Entrez le nom: ";
                std::getline(std::cin, last);
                if (last.empty())
                    throw std::runtime_error("Le nom ne peut pas être vide");

                std::cout << "Entrez le surnom: ";
                std::getline(std::cin, nick);
                if (nick.empty())
                    throw std::runtime_error("Le surnom ne peut pas être vide");

                std::cout << "Entrez le numéro de téléphone: ";
                std::getline(std::cin, phone);
                if (phone.empty())
                    throw std::runtime_error("Le numéro ne peut pas être vide");

                std::cout << "Entrez le secret: ";
                std::getline(std::cin, secret);
                if (secret.empty())
                    throw std::runtime_error("Le secret ne peut pas être vide");

                contacts[count % 8].setContact(first, last, nick, phone, secret);
                count++;
            }
            catch (const std::runtime_error& e)
            {
                std::cout << "Erreur: " << e.what() << std::endl;
            }
        }

        void searchContact() const
        {
            if (count == 0)
            {
                std::cout << "Aucun contact enregistré" << std::endl;
                return;
            }
            displayContacts();
            std::string input;
            std::cout << "Entrez l'index du contact: ";
            std::getline(std::cin, input);
            try
            {
                int index = atoi(input.c_str());
                if (index >= 0 && index < count && index < 8)
                    contacts[index].displayFull();
                else
                    std::cout << "Index invalide" << std::endl;
            }
            catch(...)
            {
                std::cout << "Index invalide" << std::endl;
            }
        }

        void displayContacts() const
        {
            if (count == 0)
            {
                std::cout << "Aucun contact enregistré" << std::endl;
                return;
            }
            std::cout << "\n|     Index|First Name| Last Name| Nickname |" << std::endl;
            std::cout << "|----------|----------|----------|----------|" << std::endl;
            for (int i = 0; i < count && i < 8; i++)
                contacts[i].displayBrief(i);
        }
};

#endif
