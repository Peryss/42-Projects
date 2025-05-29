/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:41 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 14:31:05 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack();

	private:

	std::string name;
	Weapon		&weapon;	// We need to have reference because othervise a copy would be made of the original object and if it changes this would not, this way they are connected
};

#endif
