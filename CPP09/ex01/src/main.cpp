/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:49:25 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:23:06 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		argv++;
		std::string expression;
		while (*argv)
		{
			expression += *argv;
			argv++;
		}
		RPN(expression.c_str());
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}

	return (0);
}
