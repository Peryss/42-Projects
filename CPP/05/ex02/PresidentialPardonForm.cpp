/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:34:44 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:34:46 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "target", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	if (getSigned() == false)
	    throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > getToExecute())
	    throw AForm::GradeTooLowException();

	std::cout << getTarget()
	          << " has been pardoned by Zaphod Beeblebrox."
	          << std::endl;
}
