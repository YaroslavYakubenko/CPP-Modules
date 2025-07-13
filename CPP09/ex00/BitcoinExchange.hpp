#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, float> _exchangeRates;
public:
	BitcoinExchange();
	BitcoinExchange(const std::string& dbFilename);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	
	void loadDatabase(const std::string& filename);
	void inputFile(const std::string& filename);
	std::string formatFloat(float value);
	bool isValidDate(const std::string& date) const;
};
