/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:28:00 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 16:50:55 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

int main()
{
	try
	{
		// Test with form requiring grade 10 to sign
		Form form1("Important Form", 10, 5);
		std::cout << "Form 1: " << form1 << std::endl;

		// Test with bureaucrat grade 15 (too low to sign)
		Bureaucrat lowGrade("Low Grade", 15);
		lowGrade.signForm(form1);
		std::cout << form1 << std::endl;

		// Test with bureaucrat grade 5 (can sign)
		Bureaucrat highGrade("High Grade", 5);
		highGrade.signForm(form1);
		std::cout << form1 << std::endl;

		// Test with form requiring very high grade
		Form form2("Top Secret", 1, 1);
		std::cout << "\nForm 2: " << form2 << std::endl;

		// Even highGrade (grade 5) can't sign this one
		highGrade.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
