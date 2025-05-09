#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called for target: " << this->target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
	std::cout << "ShrubberyCreationForm copy constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm assingment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called for target: " << target << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeToLowException();
	std::ofstream outFile((target + "_shrubbery").c_str());
	if (outFile.is_open()) {
		outFile << "       ^\n"
                << "      ^^^\n"
                << "     ^^^^^\n"
                << "    ^^^^^^^\n"
                << "   ^^^^^^^^^\n"
                << "  ^^^^^^^^^^^\n"
                << " ^^^^^^^^^^^^^\n"
                << "^^^^^^^^^^^^^^^\n";
		outFile.close();
		std::cout << "ShrubberyCreationForm was successful for " << target << std::endl;
	} else {
		std::cout << "Failed to create shrubbery file for " << target << std::endl;
	}
}