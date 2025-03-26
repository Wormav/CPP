/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:39:02 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/26 15:39:31 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Data.hpp>

Data::Data() : value(0) {}

Data::Data(const Data& other) : value(other.value) {}

Data& Data::operator=(const Data& other)
{
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Data::~Data() {}

int Data::getValue() const
{
    return value;
}

void Data::setValue(int value)
{
    this->value = value;
}
