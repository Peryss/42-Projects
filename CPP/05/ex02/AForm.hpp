#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_to_sign;
		const int			_to_execute;

		AForm();
		AForm& operator=(const AForm& other);
	public:
		AForm(const std::string name, const std::string target, const int to_sign, const int to_execute);
		AForm(const AForm& other);
		virtual ~AForm();

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat& bureacurat);
		std::string getName() const;
		int	getSigned() const;
		int getToSign() const;
		int getToExecute() const;
		std::string getTarget() const;

		virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif