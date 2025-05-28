#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	std::srand(static_cast<unsigned>(std::time(0)));
	int i = std::rand() % 3;
	switch (i) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*> (p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown type" << std::endl;
}

int main() {
	Base* ptr = generate();

	std::cout << "Identify by pointer: " << std::endl;
	identify(ptr);
	std::cout << "Identify by reference: " << std::endl;
	identify(*ptr);
	delete ptr;
	return 0;
}