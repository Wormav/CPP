/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:24:31 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 16:02:40 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GradeTooLowException.hpp>

const char* GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}
