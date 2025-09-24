/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:20 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:45:32 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
	this->type = "Unknown";
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type): type(type)
{
	std::cout << this->type << "Constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	this->type = other.type;
	std::cout << "Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor called on " << type << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal makes sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}
