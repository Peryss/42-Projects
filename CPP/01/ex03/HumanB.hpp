/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:09:12 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 16:21:56 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:

	HumanB(std::string name);
	~HumanB();

	void			setWeapon(Weapon &weapon);
	void			attack();

	private:

	std::string name;
	Weapon		*weapon;	// We need to have reference because othervise a copy would be made of the original object and if it changes this would not, this way they are connected
};

#endif
