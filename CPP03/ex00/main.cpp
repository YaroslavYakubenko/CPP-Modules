#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	ClapTrap c = b;

	a.attack("Beta");
	b.takeDamage(3);
	b.beRepaired(2);
	a.beRepaired(5);
	c.attack("Alpha");
	return 0;
}