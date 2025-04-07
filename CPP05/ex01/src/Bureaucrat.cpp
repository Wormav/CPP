/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:06:21 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/07 07:32:16 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name),
	grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat& Bureaucrat::operator++()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
    return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
    Bureaucrat temp = *this;
    ++(*this);
    return temp;
}

Bureaucrat& Bureaucrat::operator--()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
    return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
    Bureaucrat temp = *this;
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " <<
	bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& form)
{
    try
	{
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    }
	catch (const GradeTooLowException& e)
	{
        std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
    }
}
