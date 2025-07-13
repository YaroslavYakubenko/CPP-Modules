#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN {
private:
	std::deque<int> stack;
	void applyOperator(const std::string& op);
public:
	RPN();
	~RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);

	int evaluate(const std::string& expr);
};
