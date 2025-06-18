/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:27:19 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:27:20 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	hp = 100;
    energy= 50;
    ad = 20;
	std::cout << name << " ScavTrap " << " default constructed" << std::endl;
}


ScavTrap::ScavTrap(std::string n): ClapTrap(n)
{
	hp = 100;
    energy= 50;
    ad = 20;
    std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->ad = other.ad;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}


void ScavTrap::guardGate()
{
	if (hp > 0 && this->energy > 0)
	{
		std::cout << "ScavTrap " << name << " is in  Gate Kepper mode." << std::endl;
		this->energy--;
	}
	if (this->hp <= 0)
		std::cout << this->name << " is dead, cannot enter Gate Keeper mode!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy left, enter Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hp > 0 && this->energy > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->ad << " points of damage!" << std::endl;
		this->energy--;
	}
	if (this->hp <= 0)
		std::cout << this->name << " is dead, cannot attack!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy left, cannot attack!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hp > 0 && this->energy > 0)
	{
		std::cout << "ScavTrap " << this->name << " is being repaired for " << amount << "!" << std::endl;
		this->energy--;
		this->hp += amount;
	}
	if (this->hp <= 0)
		std::cout << this->name << "is dead, cannot be repaired!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << "has no energy left, cannot be repaired!" << std::endl;
}
