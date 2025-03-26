#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: _filename(filename), _s1(s1), _s2(s2) {}
FileReplacer::~FileReplacer() {}

bool FileReplacer::replaceInFile() {
	if (_s1.empty()) {
		std::cerr << "Error: the search string cannot be empty!" << std::endl;
		return false;
	}
	std::ifstream inputFile(_filename);
	if (!inputFile) {
		std::cerr << "Error: Could not open file: " << _filename << std::endl;
		return false;
	}
	std::ofstream outputFile(_filename + ".replace");
	if (!outputFile) {
		std::cerr << "Error: Could not create output file!" << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << replaceOccurrences(line) << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}

std::string FileReplacer::replaceOccurrences(const std::string& line) {
	std::string result;
	size_t pos = 0;
	size_t found = line.find(_s1);
	while (found != std::string::npos) {
		result += line.substr(pos, found - pos) + _s2;
		pos = found + _s1.length();
		found = line.find(_s1, pos);
	}
	result += line.substr(pos);
	return result;
}