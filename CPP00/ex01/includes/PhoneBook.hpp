/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:02:19 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/03 20:19:22 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Contact.hpp>

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;

    public:
        PhoneBook();
        void addContact();
        void searchContact() const;
};

#endif
