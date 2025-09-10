#ifndef TOOHIGHEXCEPTION_HPP
#define TOOHIGHEXCEPTION_HPP

#include <stdexcept>

class GradeTooHighException : public std::exception
{
	public:
    	const char* what() const throw();
};

#endif
