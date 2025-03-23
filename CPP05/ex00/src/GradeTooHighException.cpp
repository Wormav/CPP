/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:20:05 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 16:02:37 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GradeTooHighException.hpp>

const char* GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
