/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:10:56 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:10:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	*this = other;
	std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Cat copy operator used\n";
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow\n";
}
