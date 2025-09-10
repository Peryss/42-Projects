/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:35:04 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 11:50:56 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>


class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		RobotomyRequestForm(const RobotomyRequestForm& other);

	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();

		void execute(const Bureaucrat& bureaucrat) const;
};

#endif
