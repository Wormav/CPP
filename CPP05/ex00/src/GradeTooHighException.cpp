/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:20:05 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 15:24:11 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GradeTooHighException.hpp>

GradeTooHighException::GradeTooHighException() {}

GradeTooHighException::GradeTooHighException(const GradeTooHighException& other)
{
    *this = other;
}

GradeTooHighException& GradeTooHighException::operator=(
	const GradeTooHighException& other)
{
    if (this != &other)
	{}
    return *this;
}

GradeTooHighException::~GradeTooHighException() throw() {}

const char* GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
