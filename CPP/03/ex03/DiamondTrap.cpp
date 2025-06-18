/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:27:07 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:27:08 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name("Default")
{
    hp = FragTrap::hp;
    energy = ScavTrap::energy;
    ad = FragTrap::ad;
    std::cout << "DiamondTrap default constructor called." << std:: endl;
}

DiamondTrap::DiamondTrap(const std::string& n): ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n), name(n)
{
    hp = FragTrap::hp;        
    energy = ScavTrap::energy;  
    ad = FragTrap::ad;
    std::cout << "DiamondTrap " << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap copy assignment called." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap: " << name
              << ", and my ClapTrap name is: " << ClapTrap::name << std::endl;
}
