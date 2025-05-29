/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:29:20 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 13:51:41 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "Taka");

	if(horde != NULL)
	{
		for(int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}

	N = 0;
	horde = zombieHorde(N, "Taka");

	if(horde != NULL)
	{
		for(int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
	
	N = -23;
	horde = zombieHorde(N, "Taka");

	if(horde != NULL)
	{
		for(int i = 0; i < N; i++)
			horde[i].announce();
		delete[] horde;
	}
}
