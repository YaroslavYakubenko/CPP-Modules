#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
	loadDatabase(dbFilename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_exchangeRates = other._exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: file is empty.");
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, rateStr;
		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;
		float rate = std::atof(rateStr.c_str());
		_exchangeRates[date] = rate;
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year, month, day;
	try {
		year = std::atoi(date.substr(0, 4).c_str());
		month = std::atoi(date.substr(5, 2).c_str());
		day = std::atoi(date.substr(8, 2).c_str());
	} catch (...) {
		return false;
	}
	if (month < 1 || month > 12 || day < 1)
		return false;
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDay = 29;
	if (day > maxDay)
		return false;
	return true;
}

std::string BitcoinExchange::formatFloat(float value) {
	std::ostringstream oss;
	oss << value;
	std::string s = oss.str();
	size_t dot = s.find('.');
	if (dot != std::string::npos){
		size_t last = s.size() -1;
		while (last > dot && s[last] == '0') {
			s.erase(last, 1);
			--last;
		}
		if (s[s.size() - 1] == '.')
			s.erase(s.size() - 1, 1);
	}
	return s;
}

void BitcoinExchange::inputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: file is empty.");
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, rateStr;
		if (!std::getline(ss, date, '|') || !std::getline(ss, rateStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		rateStr.erase(0, rateStr.find_first_not_of(" \t"));
		rateStr.erase(rateStr.find_last_not_of(" \t") + 1);
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
		float value;
		try {
			value = std::atof(rateStr.c_str());
		} catch(...) {
			std::cerr << "Error: wrong value." << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
		if (it == _exchangeRates.end() || it->first != date) {
			if (it == _exchangeRates.begin()) {
				std::cerr << "Error: not available." << std::endl;
				continue;
			}
			--it;
		}
		float rate = it->second;
		float result = value * rate;
		std::cout << date << " => " << formatFloat(value) << " = " << formatFloat(result) << std::endl;
	}
	file.close();
}
