/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:26:08 by pvass             #+#    #+#             */
/*   Updated: 2025/06/23 12:56:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():_type("Unknown")
{
	//std::cout << "Materia constructor called" << std::endl;
}
	
AMateria::AMateria(std::string const & type):_type(type)
{
	//std::cout << "Materia constructor called for " << type << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
	//std::cout << "Materia copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other._type;
	//std::cout << "Materia copy operator used" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	//std::cout << "Materia destructor called" << std::endl;
}

		
std::string const & AMateria::getType() const //Returns the materia type
{
	return this->_type;
}

