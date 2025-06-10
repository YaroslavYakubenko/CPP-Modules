#include "Span.hpp"

int main()
{
	{
		std::cout << "\n--- Subject test ---" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n--- My test ---" << std::endl;
		std::srand(static_cast<unsigned int>(std::time(0)));
		try {
			Span sp(10000);
			std::vector<int> values;
			for (int i = 0; i < 10000; ++i)
				values.push_back(std::rand());
			sp.addRange(values.begin(), values.end());
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Exceptions ---" << std::endl;
		try {
			Span sp1(5);
			sp1.addNumber(42);
			std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try {
			Span sp2(2);
			sp2.addNumber(1);
			sp2.addNumber(2);
			sp2.addNumber(3);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try {
			Span sp3(5);
			int arr[] = {1, 2, 3, 4, 5, 6};
			std::vector<int> values(arr, arr + sizeof(arr) / sizeof(int));
			sp3.addRange(values.begin(), values.end());
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}