/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:43:03 by pvass             #+#    #+#             */
/*   Updated: 2025/06/23 12:58:03 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	//std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	//std::cout << "Ice copy operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor called" << std::endl;
}


AMateria* Ice::clone() const
{
	//std::cout << "Ice clone() called, deep copy made" << std::endl;
    return new Ice(*this); // deep copy
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
