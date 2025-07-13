#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&) {return *this;}

int RPN::evaluate(const std::string& expr) {
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			applyOperator(token);
		} else if (token.length() == 1 && isdigit(token[0])) {
			stack.push_back(token[0] - '0');
		} else {
			throw std::runtime_error("Error");
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Error");
	}
	return stack.back();
}

void RPN::applyOperator(const std::string& op) {
	if (stack.size() < 2)
		throw std::runtime_error("Error");
	int b = stack.back();
	stack.pop_back();
	int a = stack.back();
	stack.pop_back();
	int result;
	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	else if (op == "/") {
		if (b == 0) 
			throw std::runtime_error("Error: devision by zero");
		result = a / b;
	}
	stack.push_back(result);
}