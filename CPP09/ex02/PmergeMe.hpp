#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

class PmergeMe {
private:
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	static void sortVector(std::vector<int>& vec);
	static void sortList(std::list<int>& lst);
};

template <typename Iterator, typename T>
Iterator myLowerBound(Iterator first, Iterator last, const T& value) {
	while (first != last) {
		Iterator mid = first;
		std::advance(mid, std::distance(first, last) / 2);
		if (*mid < value)
			first = ++mid;
		else
			last = mid;
	}
	return first;
}

template <typename Container>
void makePairs(const Container& input, Container& mainChain, Container& pending, bool& hasStraggler, typename Container::value_type& straggler) {
	typename Container::const_iterator it = input.begin();
	while (std::distance(it, input.end()) >= 2) {
		typename Container::value_type a = *it++;
		typename Container::value_type b = *it++;
		if (a <= b) {
			pending.push_back(a);
			mainChain.push_back(b);
		} else {
			pending.push_back(b);
			mainChain.push_back(a);
		}
	}
	if (it != input.end()) {
		hasStraggler = true;
		straggler = *it;
	} else {
		hasStraggler = false;
	}
}

template <typename T>
std::vector<T> generateJacobsthal(size_t n) {
    std::vector<T> jacob;
    jacob.push_back(0);
    if (n > 0) jacob.push_back(1);
    while (true) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next > n)
            break;
        jacob.push_back(next);
    }

    std::vector<size_t> seq;
    seq.push_back(0);
    for (size_t k = 1; k < jacob.size(); ++k) {
        size_t cur = jacob[k];
        while (cur > jacob[k-1]) {
            seq.push_back(cur);
            --cur;
        }
    }
	std::cout << "Jacobsthal: ";
    for (size_t i = 0; i < seq.size(); ++i)
        std::cout << seq[i] << " ";
    std::cout << std::endl;
    return seq;
}

template <typename Container>
void insertSingle(Container& container, const typename Container::value_type& value) {
	typename Container::iterator pos;
	pos = myLowerBound(container.begin(), container.end(), value);
	if (pos != container.end() && *pos == value)
		return;
	container.insert(pos, value);
}

template <typename Container>
void insertPending(Container& mainChain, const Container& pending) {
	std::vector<size_t> indices = generateJacobsthal<size_t>(pending.size());
	std::vector<bool> inserted(pending.size(), false);
	size_t i;
	for (i = 0; i < indices.size(); ++i) {
		size_t index = indices[i];
		if (index >= pending.size())
			break;
		typename Container::const_iterator it = pending.begin();
		std::advance(it, index);
		insertSingle(mainChain, *it);
		inserted[index] = 1;
	}
	for (i = 0; i < inserted.size(); ++i) {
		if (!inserted[i]) {
			typename Container::const_iterator it = pending.begin();
			std::advance(it, i);
			insertSingle(mainChain, *it);
		}
	}
}

template <typename Container>
void mergeInsertSort(Container& container) {
	if (container.size() <= 1)
		return;
	Container mainChain;
	Container pending;
	bool hasStraggler;
	typename Container::value_type straggler;
	makePairs(container, mainChain, pending, hasStraggler, straggler);
	mergeInsertSort(mainChain);
	insertPending(mainChain, pending);
	if (hasStraggler)
		insertSingle(mainChain, straggler);
	container = mainChain;
}


// ./PmergeMe $(shuf -i 1-100000 -n 3000)