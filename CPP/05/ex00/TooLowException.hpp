#ifndef TOOLOWEXCEPTION_HPP
#define TOOLOWEXCEPTION_HPP

#include <exception>

class GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException();
   		virtual ~GradeTooLowException() throw();
    	virtual const char* what() const throw();
};

#endif