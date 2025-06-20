/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:39 by pvass             #+#    #+#             */
/*   Updated: 2025/06/19 16:37:37 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	return 0;
}
