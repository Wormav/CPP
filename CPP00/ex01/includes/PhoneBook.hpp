/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:02:19 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/13 11:23:22 by jlorette         ###   ########.fr       */
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

        std::string truncate(std::string str) const;

    public:
        void setContact(std::string first, std::string last, std::string nick,
                        std::string phone, std::string secret);
        void displayFull() const;
        void displayBrief(int index) const;
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;

    public:
        PhoneBook();
        void addContact();
        void searchContact() const;
        void displayContacts() const;
};

#endif
