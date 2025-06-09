/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:29:20 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 12:54:10 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie A("Foo");
	Zombie *B = newZombie("Bleeh");
	Zombie *C = new Zombie("Hwaah");

	A.announce();
	B->announce();
	C->announce();
	randomChump("RandomChump");

	delete(B);
	delete(C);
}
