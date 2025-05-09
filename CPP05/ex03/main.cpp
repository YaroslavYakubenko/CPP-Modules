#include "Intern.hpp"

int main() {
	std::cout << "\n--- Intern Form Creation Tests ---" << std::endl;
	Intern intern;
	try {
		std::cout << "\n--- Test 1: Creating ShrubberyCreationForm ---" << std::endl;
		AForm* shrubForm = intern.makeForm("shrubbery creation", "Garden");
		if (shrubForm) {
			std::cout << *shrubForm << std::endl;
			delete shrubForm;
		}

		std::cout << "\n--- Test 2: Creating RobotomyRequestFrom ---" << std::endl;
		AForm* robot = intern.makeForm("robotomy request", "Bender");
		if (robot) {
			std::cout << *robot << std::endl;
			delete robot;
		}
		std::cout << "\n--- Test 3: Creating PresidentialPardonForm ---" << std::endl;
		AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
		if (pardon) {
			std::cout << *pardon << std::endl;
			delete pardon;
		}
		std::cout << "\n--- test 4: Trying to create a non-existent form ---" << std::endl;
		AForm* unknownForm = intern.makeForm("unknown form", "Nobody");
		if (unknownForm) {
			std::cout << *unknownForm << std::endl;
			delete unknownForm;
		}
	} catch(std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

// int main() {
// 	std::cout << "\n--- Example from assingment ---" << std::endl;
// 	try {
// 		Intern someRandomIntern;
// 		AForm* rrf;

// 		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// 		if (rrf) {
// 			std::cout << *rrf << std::endl;
// 			delete rrf;
// 		}
// 	} catch (std::exception& e) {
// 		std::cerr << "Exception caught: " << e.what() << std::endl;
// 	}
// 	return 0;
// }