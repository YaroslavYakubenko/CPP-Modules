#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>

class Span {
private:
	unsigned int _maxSize;
	std::vector<int> _data;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		if (std::distance(begin, end) + _data.size() > _maxSize)
			throw std::runtime_error("Span: range exceeds maximum capacity");
		_data.insert(_data.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;
};