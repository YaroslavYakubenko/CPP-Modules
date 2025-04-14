#include "ScavTrap.hpp"

int main(void) {
	std::cout << "Creating ClapTrap:" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("Enemy");
	clap.takeDamage(3);
	clap.beRepaired(2);
	std::cout << std::endl;

	std::cout << "Creating ScavTrap:" << std::endl;
	ScavTrap scav("Scavy");
	scav.attack("Bad Guy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.quardGate();
	std::cout << std::endl;

	std::cout << "Testing copy constructor and assingment:" << std::endl;
	ScavTrap scavCopy(scav);
	ScavTrap scavAssigned;
	scavAssigned = scav;
	return 0;
}