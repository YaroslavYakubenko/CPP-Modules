#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testCreation() {
	std::cout << "\n--- Test 1: Correct creation ---" << std::endl;
	try {
		Bureaucrat high("High", 1);
		Bureaucrat low("Low", 150);
		ShrubberyCreationForm shrub("Garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testGradeException() {
	std::cout << "\n--- Test 2: grade exceptions ---" << std::endl;
	try {
		Bureaucrat tooHigh("TooHigh", 0);
	} catch(std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooLow("TooLow", 151);
	} catch(std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testSigningExecution() {
	std::cout << "\n--- Test 3: Signing and Execution ---" << std::endl;
	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm shrub("Park");
	RobotomyRequestForm robot("Wall-E");
	PresidentialPardonForm pardon("Ford Prefect");
	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);
	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);
}

void testExecutionException() {
	std::cout << "\n--- Test 4: Execution exceptions ---" << std::endl;
	Bureaucrat intern("Intern", 150);
	RobotomyRequestForm robot("Hall 9000");
	try {
		intern.executeForm(robot);
	} catch(std::exception& e) {
		std::cout << "Exception caught " << e.what() << std::endl;
	}
	try {
		intern.signForm(robot);
		intern.executeForm(robot);
	} catch(std::exception& e) {
		std::cout << "Exception caught " << e.what() << std::endl;
	}
}

int main() {
	testCreation();
	testGradeException();
	testSigningExecution();
	testExecutionException();
	return 0;
}