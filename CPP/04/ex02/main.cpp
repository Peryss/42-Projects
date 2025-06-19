/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:39 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 17:23:28 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "-------------------" << std::endl;

	Cat* cat = new Cat();

	cat->printIdeas();
	cat->setIdeas("Milk...");
	cat->printIdeas();

	delete cat;

	std::cout << "-------------------" << std::endl;

	Dog* dog = new Dog();

	dog->printIdeas();
	dog->setIdeas("Balls...");
	dog->printIdeas();

	delete dog;

	std::cout << "-------------------" << std::endl;

	//const AAnimal* animal = new AAnimal();

	return 0;
}
