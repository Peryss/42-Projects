

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		int			getGrade() const;
		std::string getName() const;
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
    			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
    			const char* what() const throw();
		};

		void signAForm(AForm& AForm);
		void executeForm(const AForm& form) const;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif