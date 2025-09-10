
#include "TooHighException.hpp"

GradeTooHighException::GradeTooHighException() {}
GradeTooHighException::~GradeTooHighException() throw() {}

const char *GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}
