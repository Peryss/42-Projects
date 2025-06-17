#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Meow\n";
}
