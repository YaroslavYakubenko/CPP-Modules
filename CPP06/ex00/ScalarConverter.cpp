#include "ScalarConverter.hpp"

bool isChar(const std::string& str) {
	return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool isInt(const std::string& str) {
	char *end;
	std::strtol(str.c_str(), &end, 10);
	return *end == '\0';
}

bool isFloat(const std::string& str) {
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	char *end;
	std::strtof(str.c_str(), &end);
	return *end == 'f';
}

bool isDouble(const std::string& str) {
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	char *end;
	std::strtod(str.c_str(), &end);
	return *end == '\0';
}

void ScalarConverter::convert(std::string literal) {
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal)) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	else if (isInt(literal)) {
		long l = std::strtol(literal.c_str(), NULL, 10);
		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max()) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
		else {
			int i = static_cast<int>(l);
			if (!std::isprint(i))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		}
	} else if (isFloat(literal)) {
		float f = std::strtof(literal.c_str(), NULL);
		if (std::isnan(f) || std::isinf(f))
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<int>(f)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

		if (std::isnan(f) || std::isinf(f))
			std::cout << "int: impossible" << std::endl;
		else if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	} else if (isDouble(literal)) {
		double d = std::strtod(literal.c_str(), NULL);
		if (std::isnan(d) || std::isinf(d))
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<int>(d)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

		if (std::isnan(d) || std::isinf(d))
			std::cout << "int: impossible" << std::endl;
		else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossilble" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}