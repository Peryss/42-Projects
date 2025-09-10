/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:35:17 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:35:18 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Unkown"), _target("target"), _signed(false), _to_sign(150), _to_execute(150) {}

AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	return (*this);
}

AForm::AForm(const std::string name, const std::string target, const int to_sign, const int to_execute): _name(name), _target(target), _signed(false), _to_sign(to_sign), _to_execute(to_execute)
{
	if (to_sign > 150)
		throw GradeTooLowException();
	if (to_sign < 1)
		throw GradeTooHighException();
	if (to_execute > 150)
		throw GradeTooLowException();
	if (to_execute < 1)
		throw GradeTooHighException();
}
AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _to_sign(other._to_sign), _to_execute(other._to_execute) {}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > _to_sign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

std::string AForm::getName() const
{
	return _name;
}

int	AForm::getSigned() const
{
	return _signed;
}

int AForm::getToSign() const
{
	return _to_sign;
}

int AForm::getToExecute() const
{
	return _to_execute;
}

std::string AForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "AForm name: " << AForm.getName();
	if (AForm.getSigned() == true)
		out << ", signed, grade to sign: ";
	else 
		out << ", not signed, grade to sign: ";
	out << AForm.getToSign() << ", grade to execute: " << AForm.getToExecute();
	return out;
}

