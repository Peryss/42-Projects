/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:27:09 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:27:10 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
	    DiamondTrap(const DiamondTrap& other);
	    DiamondTrap& operator=(const DiamondTrap& other);
    	~DiamondTrap();
	
		void whoAmI();
		using ScavTrap::attack;
		using FragTrap::beRepaired;
};


#endif
