#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n): _maxSize(n) {}

Span::~Span() {}

Span::Span(const Span& other): _maxSize(other._maxSize), _data(other._data) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_data.push_back(number);
}

int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	int minSpan = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; ++i) {
		int span = tmp[i + 1] - tmp[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());
	return max - min;
}