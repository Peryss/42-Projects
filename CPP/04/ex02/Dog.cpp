/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:35 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:46:00 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	*this = other;
	std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy operator used\n";
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const
{
	std::cout << "Wau\n";
}

void Dog::setIdeas(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, idea);
}

void Dog::printIdeas()
{
	if(this->brain != NULL)
	for (int i = 0; i < 100; i++)
		std::cout << "Idea {" << i << "}: " << this->brain->getIdea(i) << std::endl;
}