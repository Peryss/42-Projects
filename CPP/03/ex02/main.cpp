/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:23:21 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 16:28:26 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap A;
	ClapTrap B("BOB");
	ClapTrap C(B);

	std::cout << "-----------------------" << std::endl;

	A.takeDamage(5);
	A.beRepaired(2);
	A.takeDamage(10);
	A.attack("Bob");
	
	for(int i = 0; i < 11; i++)
		B.attack("Dan");
	
	ClapTrap D("Dan");
	D.attack("Bob");
	D.setAD(13);
	D.attack("Bob");

	std::cout << "-----------------------" << std::endl;
	std::cout << "\n F-------ScavTrap-------- ===\n";

	ScavTrap scav("ABC00");

	scav.attack("Bandit");
	scav.guardGate(); //special ability

	for (int i = 0; i < 51; ++i)  // Try attacking more times than available energy
	{    
		scav.attack("Training Dummy");
	}
	std::cout << "-----------------------" << std::endl;
	
	scav.guardGate(); //special ability

	scav.takeDamage(200);  // Kill the robot
	scav.attack("Enemy");

	scav.beRepaired(50); //already dead
	scav.guardGate(); //special ability

	std::cout << "-----------------------" << std::endl;

	std::cout << "\n F-------FragTrap-------- ===\n";
	FragTrap frag("FR4G-TP");
	frag.attack("Bandit");

	frag.highFivesGuys();
	frag.beRepaired(30);

	std::cout << "-----------------------" << std::endl;
	for (int i = 0; i < 50; ++i) {
	    frag.attack("Dummy");
	}
	std::cout << "-----------------------" << std::endl;
	frag.highFivesGuys();
	frag.attack("Dummy");
	frag.takeDamage(200);

	frag.attack("Zombie");
	frag.beRepaired(50);
	frag.highFivesGuys();

	std::cout << "-----------------------" << std::endl;
}