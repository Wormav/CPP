/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:49:34 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/14 11:21:31 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

void RPN(const char *expression)
{
	std::stack<double> stack;
	double a, b;

	for (; *expression; expression++)
	{
		for (;*expression == ' '; expression++);
		if (*expression == '\0')
			break;

		if (isdigit(*expression))
		{
			stack.push(*expression - 48);
		}
		else if (*expression == '/' && stack.size() >= 2 && stack.top() != 0)
		{
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a / b);
		}
		else if (*expression == '*' && stack.size() >= 2)
		{
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a * b);
		}
		else if (*expression == '+' && stack.size() >= 2)
		{
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a + b);
		}
		else if (*expression == '-' && stack.size() >= 2)
		{
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(a - b);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}

	if (stack.size() == 1)
	{
		std::cout << stack.top() << std::endl;
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}
}
