/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:53:09 by pvass             #+#    #+#             */
/*   Updated: 2025/06/23 13:14:20 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("No name")
{
	//std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(std::string const& name): _name(name)
{
	//std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	for (int i = 0; i < 4; ++i) {
	    if (other._inventory[i])
	        _inventory[i] = other._inventory[i]->clone(); // Deep copy
	    else
	        _inventory[i] = NULL;
	}
	//std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	 if (this != &other)
	{
	    _name = other._name;
	    for (int i = 0; i < 4; ++i)
	    {
	        // Clean up existing Materia to avoid memory leaks
	        if (_inventory[i])
	        {
	            delete _inventory[i];
	            _inventory[i] = NULL;
	        }
	        // Deep copy: clone Materia if it exists
	        if (other._inventory[i])
	            _inventory[i] = other._inventory[i]->clone();
	        else
	            _inventory[i] = NULL;
	    }
	}
	//std::cout << "Character deep copied" << std::endl;
	return *this;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		delete (_inventory[i]);
	//std::cout << "Character detructor called" << std::endl;
}

std::string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << "Cannot equip" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
	    if (!_inventory[i])
		{
	        _inventory[i] = m;
			std::cout << "Materia equpped to slot " << i << std::endl;
	        return;
	    }
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		_inventory[idx] = NULL;
		std::cout << "Materia unequpped from slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx] != NULL)
		{
			_inventory[idx]->use(target);
			return ;
		}
		std::cerr << "No materia at index " << idx << std::endl;
		return ;
	}
	std::cerr << "No materia" << std::endl;
}