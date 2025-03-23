/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:57:55 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 16:07:24 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
#define GRADE_TOO_HIGH_EXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif
