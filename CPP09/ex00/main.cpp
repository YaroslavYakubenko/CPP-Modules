#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	BitcoinExchange btc;

	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		btc.loadDatabase("data.csv");
		btc.inputFile(av[1]);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}