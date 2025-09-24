/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:03 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:11:04 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
	std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Dog copy operator used\n";
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const
{
	std::cout << "Wau\n";
}
