#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack() const;
};

#endif