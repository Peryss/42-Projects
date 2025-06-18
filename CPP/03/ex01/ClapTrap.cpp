/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:22:51 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:22:52 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Unknown"), hp(10), energy(10), ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap (std::string name): name(name), hp(10), energy(10), ad(0)
{
	std::cout << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->ad = other.ad;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->ad = other.ad;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hp > 0 && this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->ad << " points of damage!" << std::endl;
		this->energy--;
	}
	if (this->hp <= 0)
		std::cout << this->name << " is dead, cannot attack!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy left, cannot attack!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hp > amount)
	{
		this->hp -= amount;
		std::cout << this->name << " took " << amount << " points of damage!" << std::endl;
	}
	else if (hp == amount)
	{
		this->hp -= amount;
		std::cout << this->name << " took " << amount << " points of damage and died!" << std::endl;
	}
	else if (hp < amount)
	{
		this->hp -= this->hp;
		std::cout << this->name << " took " << amount << " points of damage and died!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp > 0 && this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name << " is being repaired for " << amount << "!" << std::endl;
		this->energy--;
		this->hp += amount;
	}
	if (this->hp <= 0)
		std::cout << this->name << "is dead, cannot be repaired!" << std::endl;
	else if (this->energy <= 0)
		std::cout << this->name << "has no energy left, cannot be repaired!" << std::endl;
}

void ClapTrap::setAD(unsigned int amount)
{
	this->ad = amount;
	std::cout << this->name <<"'s AD set to: " << amount << std::endl;
}