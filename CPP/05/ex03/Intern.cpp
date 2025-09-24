/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:35:28 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 12:04:18 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cctype>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

struct FormSpec {
	const char* name;
	AForm* (*factory)(const std::string& target);
};

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}
static AForm* createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

static std::string toLowerStr(const std::string& s) {
	std::string out; out.reserve(s.size());
	for (std::string::size_type i = 0; i < s.size(); ++i)
	    out.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(s[i]))));
	return out;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const 
{
	static const FormSpec specs[] = {
	    { "presidential pardon", &createPardon   },
	    { "robotomy request",    &createRobotomy },
	    { "shrubbery creation",  &createShrubbery}
	};

	const std::string key = toLowerStr(formName);
	for (size_t i = 0; i < sizeof(specs) / sizeof(specs[0]); ++i) {
	    if (key == specs[i].name) {
	        std::cout << "Intern creates " << specs[i].name << std::endl;
	        return specs[i].factory(target);
	    }
	}
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Intern cannot create form (Unknown form type)";
}
