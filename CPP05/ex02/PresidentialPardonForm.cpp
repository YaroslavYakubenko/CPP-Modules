#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), target("default") {
	std::cout << "PresidentialPardonFrom default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called for target: " << this->target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {
	std::cout << "PresidentialPardonForm copy constructor called for target: " << target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm assingment operator called for target: " << target << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called for target: " << target << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeToLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
