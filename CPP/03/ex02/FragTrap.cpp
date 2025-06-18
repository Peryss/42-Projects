/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:23:13 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:23:15 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	hp = 100;
    energy= 100;
    ad = 30;
	std::cout << name << " FragTrap " << " default constructed" << std::endl;
}


FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	hp = 100;
    energy= 100;
    ad = 30;
    std::cout << "FragTrap " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->ad = other.ad;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << name << std::endl;
}


void FragTrap::highFivesGuys()
{
	if (hp > 0 && this->energy > 0)
	{
		std::cout << "FragTrap " << name << " asks for a high five!." << std::endl;
		this->energy--;
	}
	if (this->hp <= 0)
		std::cout << this->name << " is dead, cannot ask for a high five!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy left, cannot ask for a high five" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->hp > 0 && this->energy > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->ad << " points of damage!" << std::endl;
		this->energy--;
	}
	if (this->hp <= 0)
		std::cout << this->name << " is dead, cannot attack!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy left, cannot attack!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->hp > 0 && this->energy > 0)
	{
		std::cout << "FragTrap " << this->name << " is being repaired for " << amount << "!" << std::endl;
		this->energy--;
		this->hp += amount;
	}
	if (this->hp <= 0)
		std::cout << this->name << "is dead, cannot be repaired!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << "has no energy left, cannot be repaired!" << std::endl;
}
