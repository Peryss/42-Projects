/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:32:31 by pvass             #+#    #+#             */
/*   Updated: 2025/06/23 13:28:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;


	std::cout << "\n----Inventory Overflow Test-------" << std::endl;

	me = new Character("me");
	bob = new Character("bob");
	
	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");
	AMateria* m3 = src->createMateria("ice");
	AMateria* m4 = src->createMateria("cure");
	AMateria* m5 = src->createMateria("ice"); // 5th materia

	me->equip(m1);
	me->equip(m2);
	me->equip(m3);
	me->equip(m4);
	me->equip(m5); // should be ignored or handled gracefully

	for (int i = 0; i < 4; i++)
	{
		me->use(i, *bob);
	}
	// Clean up manually if m5 was not stored
	delete m5;

	std::cout << "\n---- Unequip and Re-equip Test ------" << std::endl;

	me->unequip(2); // Unequip 3rd slot
	delete m3;
	AMateria* m6 = src->createMateria("cure");
	me->equip(m6);  // Should go into slot 2
	for (int i = 0; i < 4; i++)
	{
		me->use(i, *bob);
	}

	std::cout << "\n----- Unknown Materia Test ------" << std::endl;

	AMateria* unknown = src->createMateria("fire"); // not learned
	if (!unknown)
	    std::cout << "Unknown materia type 'fire' correctly returned NULL" << std::endl;
	else
	{
	    std::cout << "ERROR: Unknown materia type should not be created!" << std::endl;
	    delete unknown;
	}

	for (int i = 0; i < 4; i++)
	{
		me->use(i, *bob);
	}

	std::cout << "\n---------Clone Consistency Test--------" << std::endl;

	AMateria* original = new Ice();
	AMateria* clone = original->clone();

	std::cout << "Original type: " << original->getType() << std::endl;
	std::cout << "Clone type: " << clone->getType() << std::endl;

	delete original;
	delete clone;

	std::cout << "--------------------------" << std::endl;

	delete src;
	delete bob;
	delete me;

	return 0;
}