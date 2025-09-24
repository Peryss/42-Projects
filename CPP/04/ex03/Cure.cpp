/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:56:01 by pvass             #+#    #+#             */
/*   Updated: 2025/06/23 12:57:53 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	//std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	//std::cout << "Cure copy operator called" << std::endl;
	if (this != &other)
	    this->_type = other._type;
	return *this;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	//std::cout << "Cure clone() called, deep copy made" << std::endl;
	return new Cure(*this); // deep copy
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}