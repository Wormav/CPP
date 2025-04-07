/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:28:00 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/07 07:31:52 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main()
{
    try
	{
        Bureaucrat defaultBureaucrat;
        std::cout << defaultBureaucrat << std::endl;

        Bureaucrat highBureaucrat("High Bureaucrat", 2);
        Bureaucrat lowBureaucrat("Low Bureaucrat", 150);

        std::cout << highBureaucrat << std::endl;
        std::cout << lowBureaucrat << std::endl;

        ++highBureaucrat;
        std::cout << highBureaucrat << std::endl;

        --lowBureaucrat;
        std::cout << lowBureaucrat << std::endl;

        Bureaucrat copyBureaucrat = highBureaucrat;
        std::cout << copyBureaucrat << std::endl;

        Bureaucrat assignBureaucrat;
        assignBureaucrat = lowBureaucrat;
        std::cout << assignBureaucrat << std::endl;

        Bureaucrat invalidBureaucrat("Invalid Bureaucrat", 151);
    }
	catch (const GradeTooHighException& e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
	catch (const GradeTooLowException& e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat tooLowBureaucrat("Too Low Bureaucrat", 0);
        std::cout << tooLowBureaucrat << std::endl;
        --tooLowBureaucrat;
    }
	catch (const GradeTooHighException& e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const GradeTooLowException& e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
