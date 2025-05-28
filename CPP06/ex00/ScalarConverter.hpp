#pragma once

#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::fixed, std::setprecision
#include <string>       // std::string
#include <cstdlib>      // std::strtol, std::strtof, std::strtod
#include <climits>      // INT_MIN, INT_MAX
#include <cfloat>       // FLT_MAX, FLT_MIN
#include <cmath>        // std::isnan, std::isinf
#include <limits>       // std::numeric_limits

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
public:
	static void convert(std::string literal);
};