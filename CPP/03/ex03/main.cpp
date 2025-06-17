
#include "DiamondTrap.hpp"

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
	std::cout << "\n F-------ScavTrap-------- ===\n";

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

	std::cout << "-----------------------" << std::endl;

	std::cout << "\n F-------FragTrap-------- ===\n";
    FragTrap frag("FR4G-TP");
    frag.attack("Bandit");

    frag.highFivesGuys();
    frag.beRepaired(30);

    std::cout << "\n=== Depleting energy ===\n";
    for (int i = 0; i < 50; ++i) {
        frag.attack("Dummy");
    }
	std::cout << "-----------------------" << std::endl;
	frag.highFivesGuys();
    frag.attack("Dummy");
    frag.takeDamage(200);

    frag.attack("Zombie");
    frag.beRepaired(50);
    frag.highFivesGuys();

	std::cout << "-----------------------" << std::endl;
    FragTrap fragCopy(frag); // will copy dead bot
    FragTrap fragAssigned;
    fragAssigned = frag;

	std::cout << "-----------------------" << std::endl;
	std::cout << "\n F-------DiamondTrap-------- ===\n";

	DiamondTrap dt("D1A-M0ND");

	dt.attack("Training Dummy"); // uses ScavTrap::attack
	dt.takeDamage(20);
	dt.beRepaired(10);
	dt.whoAmI(); // unique to DiamondTrap

	for (int i = 0; i < 51; ++i)
		dt.attack("Brick Wall");

	std::cout << "-----------------------" << std::endl;
	dt.takeDamage(200); // kill
	dt.attack("Zombie");
	dt.beRepaired(50);
	dt.whoAmI();

	std::cout << "-----------------------" << std::endl;
	DiamondTrap dtAssigned;
	dtAssigned = dt;
	dtAssigned.whoAmI();

}