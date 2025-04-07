/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:18:56 by jlorette          #+#    #+#             */
/*   Updated: 2025/04/07 09:46:39 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		Form();

	public:
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
