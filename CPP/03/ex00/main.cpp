/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:22:45 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 16:20:10 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
}
