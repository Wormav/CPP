/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:17:43 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 23:23:07 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;

    srand(time(NULL));
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}
