/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:28:00 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/23 23:22:35 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm()
{
    std::cout << "\n======== TEST SHRUBBERY CREATION FORM ========" << std::endl;

    std::cout << "Creating ShrubberyCreationForm for 'Garden'" << std::endl;
    ShrubberyCreationForm form("Garden");
    std::cout << form << std::endl;

    std::cout << "\nCreating bureaucrats:" << std::endl;
    Bureaucrat higher("Manager", 137);
    Bureaucrat lower("Intern", 146);
    std::cout << higher << std::endl;
    std::cout << lower << std::endl;

    std::cout << "\n--- Signature Test ---" << std::endl;
    std::cout << "Intern attempts to sign (grade " << lower.getGrade() << ", needs 145):" << std::endl;
    try {
        lower.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nManager attempts to sign (grade " << higher.getGrade() << ", needs 145):" << std::endl;
    try {
        higher.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Execution Test ---" << std::endl;
    std::cout << "Intern attempts to execute (grade " << lower.getGrade() << ", needs 137):" << std::endl;
    try {
        lower.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nManager attempts to execute (grade " << higher.getGrade() << ", needs 137):" << std::endl;
    try {
        higher.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm()
{
    std::cout << "\n======== TEST ROBOTOMY REQUEST FORM ========" << std::endl;

    std::cout << "Creating RobotomyRequestForm for 'Bender'" << std::endl;
    RobotomyRequestForm form("Bender");
    std::cout << form << std::endl;

    std::cout << "\nCreating bureaucrats:" << std::endl;
    Bureaucrat higher("Director", 45);
    Bureaucrat lower("Assistant", 73);
    std::cout << higher << std::endl;
    std::cout << lower << std::endl;

    std::cout << "\n--- Signature Test ---" << std::endl;
    std::cout << "Assistant attempts to sign (grade " << lower.getGrade() << ", needs 72):" << std::endl;
    try {
        lower.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Execution Test ---" << std::endl;
    std::cout << "Assistant attempts to execute (grade " << lower.getGrade() << ", needs 45):" << std::endl;
    try {
        lower.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nDirector attempts to execute (grade " << higher.getGrade() << ", needs 45):" << std::endl;
    try {
        higher.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test with Director signing and executing ---" << std::endl;
    RobotomyRequestForm secondForm("C3PO");
    std::cout << "Director signs the form for C3PO:" << std::endl;
    try {
        higher.signForm(secondForm);
        std::cout << "Director attempts to execute the form:" << std::endl;
        higher.executeForm(secondForm);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm()
{
    std::cout << "\n======== TEST PRESIDENTIAL PARDON FORM ========" << std::endl;

    std::cout << "Creating PresidentialPardonForm for 'Arthur Dent'" << std::endl;
    PresidentialPardonForm form("Arthur Dent");
    std::cout << form << std::endl;

    std::cout << "\nCreating bureaucrats:" << std::endl;
    Bureaucrat president("President", 5);
    Bureaucrat minister("Minister", 20);
    std::cout << president << std::endl;
    std::cout << minister << std::endl;

    std::cout << "\n--- Signature Test ---" << std::endl;
    std::cout << "Minister attempts to sign (grade " << minister.getGrade() << ", needs 25):" << std::endl;
    try {
        minister.signForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Execution Test ---" << std::endl;
    std::cout << "Minister attempts to execute (grade " << minister.getGrade() << ", needs 5):" << std::endl;
    try {
        minister.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nPresident attempts to execute (grade " << president.getGrade() << ", needs 5):" << std::endl;
    try {
        president.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    try {
        testShrubberyCreationForm();
        testRobotomyRequestForm();
        testPresidentialPardonForm();
    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}
