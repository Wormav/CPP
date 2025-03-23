/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:02:23 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 16:07:32 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
#define GRADE_TOO_LOW_EXCEPTION_HPP

#include <exception>

class GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif
