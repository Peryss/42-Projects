#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "-------------------" << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	for(int i = 0; i < 100; i++)
		dog;

	return 0;
}
