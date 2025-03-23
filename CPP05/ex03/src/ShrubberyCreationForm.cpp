/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:17:43 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 23:23:15 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
	{
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open())
	{
        file << "       _-_\n"
             << "    /~~   ~~\\\n"
             << " /~~         ~~\\\n"
             << "{               }\n"
             << " \\  _-     -_  /\n"
             << "   ~  \\\\ //  ~\n"
             << "_- -   | | _- _\n"
             << "  _ -  | |   -_\n"
             << "      // \\\\\n";
        file.close();
    }
	else
        throw std::runtime_error("Unable to open file");
}
