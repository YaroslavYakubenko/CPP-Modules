#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap copy assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "Claptrap " << name << " cannot attack. No energy or hitpoints left!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " took " << amount << " damage! Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std:: cout << "ClapTrap " << name << " cannot repair. No energy or hitpoints left!" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaired itself by " << amount << " points! Current HP: " << hitPoints << std::endl;
}