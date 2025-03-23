#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat
{
	private:
    	const std::string name;
    	int grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		Bureaucrat& operator++();
		Bureaucrat operator++(int);
		Bureaucrat& operator--();
		Bureaucrat operator--(int);

		friend std::ostream& operator<<(std::ostream& os,
			const Bureaucrat& bureaucrat);
};

#endif
