#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		int result = rpn.evaluate(av[1]);
		std::cout << result << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}