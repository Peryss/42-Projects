
#include "TooLowException.hpp"

GradeTooLowException::GradeTooLowException() {}
GradeTooLowException::~GradeTooLowException() throw() {}

const char *GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}