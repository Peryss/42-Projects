/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:10 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:11:11 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Unknown";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type): type(type)
{
	std::cout << this->type << "Constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called on " << type << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
