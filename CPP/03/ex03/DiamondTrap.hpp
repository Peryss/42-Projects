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
