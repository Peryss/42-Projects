#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		ideas[i] = "Bla bla bla...";
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain copy constructed" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy assignment operator used" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "No idea!";
}
