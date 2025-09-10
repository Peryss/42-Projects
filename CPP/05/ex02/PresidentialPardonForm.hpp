#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
    	PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	
	public:
    	explicit PresidentialPardonForm(const std::string& target);
    	PresidentialPardonForm(const PresidentialPardonForm& other);
    	~PresidentialPardonForm();

    	void execute(const Bureaucrat& bureaucrat) const;
};

#endif
