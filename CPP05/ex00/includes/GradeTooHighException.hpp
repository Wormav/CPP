/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:57:55 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 15:12:26 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception
{
	public:

		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException& other);
		GradeTooHighException& operator=(const GradeTooHighException& other);
		virtual ~GradeTooHighException() throw();

		virtual const char* what() const throw();
};

#endif
