#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called for target: " << this->target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {
	std::cout << "RobotomyrequestForm copy constructor called for target: " << target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm assingment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called for target: " << target << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeToLowException();
	srand(time(NULL));
	if (rand() % 2 == 0) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << target << std::endl;
	}
}
