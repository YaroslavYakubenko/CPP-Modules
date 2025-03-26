#include "FileReplacer.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	FileReplacer replacer(av[1], av[2], av[3]);
	if (!replacer.replaceInFile()) {
		return 1;
	}
	std::cout << "Replacement done. Output file: " << av[1] << ".replace" << std::endl;
	return 0;
}