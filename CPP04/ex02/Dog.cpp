#include "Dog.hpp"

Dog::Dog() : AAnimal(), brain(new Brain()) {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment constructor called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, std::string idea) {
	if (brain)
		brain->setIdea(index, idea);
}

const std::string& Dog::getIdea(int index) const {
	return brain->getIdea(index);
}