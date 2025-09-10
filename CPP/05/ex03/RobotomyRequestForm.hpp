/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:35:57 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:35:59 by pvass            ###   ########.fr       */
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

	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& other);

		void execute(const Bureaucrat& bureaucrat) const;
};

#endif
