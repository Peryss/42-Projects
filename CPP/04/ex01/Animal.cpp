/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:20 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:11:21 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Unknown";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type): type(type)
{
	std::cout << this->type << "Constructed" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor called on " << type << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
