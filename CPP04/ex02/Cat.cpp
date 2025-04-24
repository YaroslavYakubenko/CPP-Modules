#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain) {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assingment c=operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, std::string idea) {
	if (brain)
		brain->setIdea(index, idea);
}

const std::string& Cat::getIdea(int index) const {
	return brain->getIdea(index);
}