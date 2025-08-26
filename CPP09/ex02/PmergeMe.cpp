#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;

}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec) {
	mergeInsertSort(vec);
}

void PmergeMe::sortList(std::list<int>& lst) {
	mergeInsertSort(lst);
}