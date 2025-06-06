#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << name << "Zombie created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}