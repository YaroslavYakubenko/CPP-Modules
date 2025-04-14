#include "FragTrap.hpp"

int main(void)
{
    FragTrap Vayne("Vayne");
    Vayne.attack("Nick");
    Vayne.beRepaired(4);
    Vayne.attack("Nick");
    Vayne.takeDamage(50);
    Vayne.takeDamage(55);
    Vayne.takeDamage(55);
    Vayne.highFivesGuys();
    return(0);
}