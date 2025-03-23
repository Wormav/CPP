/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:48 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 16:51:40 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form(const std::string& name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
	signGrade(other.signGrade), execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << ", Signed: " <<
	(form.getIsSigned() ? "Yes ✅" : "No ❌")
    << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: "
	<< form.getExecGrade();
    return os;
}
