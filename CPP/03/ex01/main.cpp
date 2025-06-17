#include "ScavTrap.hpp"

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

	std::cout << "-----------------------" << std::endl;

    ScavTrap scav("ABC00");

    scav.attack("Bandit");
	scav.guardGate(); //special ability

    for (int i = 0; i < 51; ++i)  // Try attacking more times than available energy
    {    
		scav.attack("Training Dummy");
	}
	std::cout << "-----------------------" << std::endl;
	
	scav.guardGate(); //special ability

    scav.takeDamage(200);  // Kill the robot
    scav.attack("Enemy");

    scav.beRepaired(50); //already dead
    scav.guardGate(); //special ability
}