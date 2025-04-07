/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:28:00 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/07 07:33:30 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

int main()
{
	try
	{
		Form form1("Important Form", 10, 5);
		std::cout << "Form 1: " << form1 << std::endl;

		Bureaucrat lowGrade("Low Grade", 15);
		lowGrade.signForm(form1);
		std::cout << form1 << std::endl;

		Bureaucrat highGrade("High Grade", 5);
		highGrade.signForm(form1);
		std::cout << form1 << std::endl;

		Form form2("Top Secret", 1, 1);
		std::cout << "\nForm 2: " << form2 << std::endl;

		highGrade.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
