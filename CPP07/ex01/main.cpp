#include "iter.hpp"

void printInt(const int& x){
	std::cout << x << " ";
}

void toUpper(char& c) {
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
}

void printChar(const char& c) {
	std::cout << c << " ";
}

int main() {
	int nums[] = {1, 2, 3, 4, 5};
	std::cout << "Original ints: ";
	iter(nums, 5, printInt);
	std::cout << "\n";

	char letters[] = {'a', 'b', 'c' , 'd', 'e'};
	std::cout << "Original chars: ";
	iter(letters, 5, printChar);
	std::cout << "\n";
	iter(letters, 5, toUpper);
	std::cout << "Uppercased chars: ";
	iter(letters, 5, printChar);
	std::cout << "\n";
	return 0;
}