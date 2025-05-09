#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Intern assingment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	const std::string forNames[] = {"shrubbery creation", "Robotomy request", "presidential pardon"};
	AForm* forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; ++i) {
		if (formName == forNames[i]) {
			std::cout << "Intern creats" << formName << std::endl;
			return forms[i];
		}
		delete forms[i];
	}
	std::cout << "Error: Form not found!" << std::endl;
	return NULL;
}