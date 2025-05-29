/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:27:43 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 13:52:21 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie ()
{
	std::cout << "Zombie constructed..." << std::endl;
}

Zombie::Zombie(std::string n): name(n)
{
	std::cout << "Zombie constructed..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " destructed..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name (std::string name)
{
	this->name = name;
}
