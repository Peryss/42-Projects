/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:49 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 16:19:49 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:

	Weapon(const std::string &type);
	~Weapon();
	
	void			setType(const std::string &type);
	const std::string 	getType() const;

	private:

	std::string type;	
	
};

#endif
