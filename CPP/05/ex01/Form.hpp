/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:34:08 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:34:10 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_to_sign;
		const int			_to_execute;

		Form();
		Form& operator=(const Form& other);
	public:
		Form(const std::string name, const int to_sign, const int to_execute);
		Form(const Form& other);
		~Form();

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

		void beSigned(Bureaucrat& bureacurat);
		std::string getName() const;
		int	getSigned() const;
		int getToSign() const;
		int getToExecute() const;
};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif