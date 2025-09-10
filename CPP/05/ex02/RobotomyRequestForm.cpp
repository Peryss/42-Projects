/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:34:50 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:35:02 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "target", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o) : AForm(o) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o) {
    (void)o; return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const {
    if (getSigned() == false)
        throw AForm::NotSignedException();
    if (b.getGrade() > this->getToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "*** BZZZZT DRILLING NOISES ***\n";

    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << getTarget() << ".\n";
}

