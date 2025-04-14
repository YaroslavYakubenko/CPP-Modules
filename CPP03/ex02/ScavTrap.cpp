#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name) {
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ScavTrap" << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << name << " has entered Gate Keeper mode." << std::endl;
	}
}

void ScavTrap::quardGate() {
	std::cout << "ScavTrap is now in Gate Kepper mode!" << std::endl;
}