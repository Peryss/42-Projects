/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:08 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:19:40 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();


	delete i;
    delete j;
    delete meta;

	std::cout << "--------------------------------" << std::endl;

	const WrongAnimal* base = new WrongAnimal();
	const WrongAnimal* x = new WrongCat();
	const WrongCat* y = new WrongCat();

	std::cout << x->getType() << " " << std::endl;
	x->makeSound(); //should not output the cat sound!
	base->makeSound();

	y->makeSound();

	delete y;
	delete x;
    delete base;

	

    return 0;
}
