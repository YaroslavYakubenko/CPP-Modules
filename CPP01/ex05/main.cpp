#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nTesting INFO level:" << std::endl;
	harl.complain("INFO");
	std::cout << "\nTesting WARNING level:" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nTesting ERROR level:" << std::endl;
	harl.complain("ERROR");
	std::cout << "\nTesting unknown level:" << std::endl;
	harl.complain("RANDOM");
	return 0;
}