/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:25:16 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 23:45:35 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Intern.hpp>
#include <iostream>

int main(void)
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* ppf;
    AForm* scf;
    AForm* unknown;

    std::cout << "\n----- INTERN CLASS TEST -----\n" << std::endl;

    Bureaucrat boss("Boss", 1);

    std::cout << "1. Testing robotomy request" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n2. Testing presidential pardon" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
    if (ppf)
    {
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n3. Testing shrubbery creation" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf)
    {
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    std::cout << "\n4. Testing non-existent form" << std::endl;
    unknown = someRandomIntern.makeForm("coffee request", "Office");
    if (unknown)
    {
        delete unknown;
    }
    else
    {
        std::cout << "The form could not be created" << std::endl;
    }

    std::cout << "\n----- END OF TESTS -----\n" << std::endl;

    return 0;
}
