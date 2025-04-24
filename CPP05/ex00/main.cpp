#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;
		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;
		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;
		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	try {
		Bureaucrat b("Bob", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
	try {
		Bureaucrat c("Carl", 0);
		std::cout << c << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught during creation: " << e.what() << std::endl;
	}
	try {
		Bureaucrat d("Diana", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught during creation: " << e.what() << std::endl;
	}
	return 0;
}