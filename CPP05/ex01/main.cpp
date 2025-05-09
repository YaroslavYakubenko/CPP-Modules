#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "--- Test 1: Successful signing ---" << std::endl;
	Bureaucrat john("John", 5);
	Form taxForm("Tax Form", 10, 20);
	john.signForm(taxForm);
	std::cout << taxForm << std::endl;

	std::cout << "\n--- Test 2: Signing with insufficient grade ---" << std::endl;
	Bureaucrat bob("Bob", 50);
	Form secretForm("Secret Form", 30, 40);
	bob.signForm(secretForm);
	std::cout << secretForm << std::endl;

	std::cout << "\n--- Test 3: Form with invalid grade (too high) ---" << std::endl;
	try {
		Form invalidForm1("InvaligHigh", 0, 50);
	}
	catch (std::exception& e) {
		std::cout << "Exception caught (high): " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Form with invalid grade (too low) ---" << std::endl;
	try {
		Form invalidForm2("InvalidLow", 151, 50);
	}
	catch (std::exception& e) {
		std::cout << "Exception caught (low): " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Double signing ---" << std::endl;
	Bureaucrat alice("Alice", 3);
	Form visaForm("Visa", 10, 10);
	alice.signForm(visaForm);
	alice.signForm(visaForm);
	std::cout << visaForm << std::endl;

	std::cout << "\n--- Test 6: Multiple forms, multiple bureaucrats ---" << std::endl;
	Bureaucrat a("A", 1);
	Bureaucrat b("B", 100);
	Form form1("Form1", 5, 5);
	Form form2("Form2", 90, 90);
	Form form3("Form3", 110, 110);
	a.signForm(form1);
	b.signForm(form2);
	b.signForm(form3);
	a.signForm(form3);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	return 0;
}