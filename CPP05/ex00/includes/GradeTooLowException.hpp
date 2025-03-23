/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:02:23 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 15:13:11 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include <exception>

class GradeTooLowException : public std::exception
{
	public:

		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException& other);
		GradeTooLowException& operator=(const GradeTooLowException& other);
		virtual ~GradeTooLowException() throw();

		virtual const char* what() const throw();
};

#endif
