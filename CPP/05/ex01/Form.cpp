#include "Form.hpp"

Form::Form(): _name("Unkown"), _signed(false), _to_sign(150), _to_execute(150) {}

Form& Form::operator=(const Form& other)
{
	(void)other;
	return (*this);
}

Form::Form(const std::string name, const int to_sign, const int to_execute): _name(name), _signed(false), _to_sign(to_sign), _to_execute(to_execute)
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
Form::Form(const Form& other): _name(other._name), _signed(other._signed), _to_sign(other._to_sign), _to_execute(other._to_execute) {}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > _to_sign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::string Form::getName() const
{
	return _name;
}

int	Form::getSigned() const
{
	return _signed;
}

int Form::getToSign() const
{
	return _to_sign;
}

int Form::getToExecute() const
{
	return _to_execute;
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << "Form name: " << Form.getName();
	if (Form.getSigned() == true)
		out << ", signed, grade to sign: ";
	else 
		out << ", not signed, grade to sign: ";
	out << Form.getToSign() << ", grade to execute: " << Form.getToExecute();
	return out;
}

