#include "Dog.hpp"

Dog::Dog(): brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
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
