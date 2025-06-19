/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:29 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:45:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	*this = other;
	std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy operator used\n";
	return *this;
}

Cat::~Cat()
{
	delete brain;
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow\n";
}

void Cat::setIdeas(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, idea);
}

void Cat::printIdeas()
{
	if(this->brain != NULL)
	for (int i = 0; i < 100; i++)
		std::cout << "Idea {" << i << "}: " << this->brain->getIdea(i) << std::endl;
}
