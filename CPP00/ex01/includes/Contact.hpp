/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:24:46 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/26 14:25:30 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

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

#endif
