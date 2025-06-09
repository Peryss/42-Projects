/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:27:37 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 12:53:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:

	Zombie ( std::string n );
	~Zombie ();
	void announce ( void );

	private:

	std::string name;

};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif
