/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:27:37 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 13:42:34 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:

	Zombie () ;
	Zombie ( std::string n );
	~Zombie ();
	void	announce ();
	void	set_name ( std::string name );

	private:

	std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
