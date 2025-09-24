/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:34:47 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 11:50:32 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		PresidentialPardonForm(const PresidentialPardonForm& other);
	
	public:
		explicit PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();

		void execute(const Bureaucrat& bureaucrat) const;
};

#endif
