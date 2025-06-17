#include "Cat.hpp"

Cat::Cat(): brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
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
