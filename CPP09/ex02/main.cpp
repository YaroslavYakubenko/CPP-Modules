#include "PmergeMe.hpp"

long getMicroseconds() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000L + tv.tv_usec;
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: no input." << std::endl;
		return 1;
	}
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 1; i < ac; ++i) {
		std::string token(av[i]);
		if (token.find_first_not_of("0123456789") != std::string::npos) {
			std::cerr << "Error: invalid input '" << token << "'" << std::endl;
			return 1;
		}
		long val = std::strtol(token.c_str(), NULL, 10);
		if (val < 0 || val > 2147483647) {
			std::cerr << "Error: out of range number '" << token << "'" << std::endl;
			return 1;
		}
		vec.push_back(static_cast<int>(val));
		lst.push_back(static_cast<int>(val));
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	long startVec = getMicroseconds();
	PmergeMe::sortVector(vec);
	long endVec = getMicroseconds();

	long startList = getMicroseconds();
	PmergeMe::sortList(lst);
	long endList = getMicroseconds();

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << (endVec - startVec) / 1000.0 << " us" << std::endl;
	std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << (endList - startList) / 1000.0 << " us" << std::endl;

	return 0;
}