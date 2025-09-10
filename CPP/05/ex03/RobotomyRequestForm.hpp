#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>


class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& other);

		void execute(const Bureaucrat& bureaucrat) const;
};

#endif
