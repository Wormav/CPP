/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:28:24 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 23:44:54 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <iostream>

Intern::Intern(void){}

Intern::Intern(const Intern &cpy)
{
    (void)cpy;
}

Intern::~Intern(void){}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

AForm *Intern::createShrubbery(std::string const &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidential(std::string const &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomy(std::string const &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
    std::string forms[3] =
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(Intern::*functions[3])(std::string const &target) const =
	{
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*functions[i])(target);
        }
    }

    std::cout << "Intern cannot create form: " << formName << " (form not found)" << std::endl;
    return NULL;
}
