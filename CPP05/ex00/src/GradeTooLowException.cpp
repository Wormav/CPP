/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:24:31 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 15:27:49 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GradeTooLowException.hpp>

GradeTooLowException::GradeTooLowException() {}

GradeTooLowException::GradeTooLowException(const GradeTooLowException& other)
{
    *this = other;
}

GradeTooLowException& GradeTooLowException::operator=(
	const GradeTooLowException& other) {
    if (this != &other)
	{
	}
	return *this;
}

GradeTooLowException::~GradeTooLowException() throw(){}

const char* GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}
