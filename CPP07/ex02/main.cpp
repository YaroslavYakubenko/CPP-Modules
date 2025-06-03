#include "Array.hpp"

int main() {
	try {
		//empty array
		Array<int> empty;
		std::cout << "empty.size() = " << empty.size() << std::endl;

		//array of 5 elements
		Array<int> numbers(5);
		for (unsigned int i = 0; i < numbers.size(); ++i)
			numbers[i] = static_cast<int>(i * 10);
		std::cout << "numbers: ";
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;

		//copy constructor
		Array<int> copy(numbers);
		std::cout << "copy: ";
		for (unsigned int i = 0; i < copy.size(); ++i)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		//assignment
		Array<int> assigned;
		assigned = numbers;
		std::cout << "assigned: ";
		for (unsigned int i = 0; i < assigned.size(); ++i)
			std::cout << assigned[i] << " ";
		std::cout << std::endl;

		//check out of bounds
		std::cout << "Trying to out of bounds access..." << std::endl;
		std::cout << numbers[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
