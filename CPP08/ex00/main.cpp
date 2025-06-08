#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 2);
	try {
		std::vector<int>::const_iterator it = easyfind(vec, 4);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		easyfind(vec, 7);
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}