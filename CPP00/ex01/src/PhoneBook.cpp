/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:31:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/13 11:31:07 by jlorette         ###   ########.fr       */
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
    catch (const std::runtime_error &e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
}

void PhoneBook::searchContact() const
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

    std::string input;
    std::cout << "Entrez l'index du contact: ";
    std::getline(std::cin, input);
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            std::cout << "Erreur: l'index doit être un nombre" << std::endl;
            return;
        }
    }
    int index = std::atoi(input.c_str());
    if (index < 0 || index >= count || index >= 8)
    {
        std::cout << "Erreur: index invalide" << std::endl;
        return;
    }
    contacts[index].displayFull();
}

void PhoneBook::displayContacts() const
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
