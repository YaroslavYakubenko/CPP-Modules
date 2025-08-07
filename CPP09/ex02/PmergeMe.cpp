#include "PmergeMe.hpp"

void PmergeMe::sortVector(std::vector<int>& vec) {
	mergeInsertSort(vec);
}

void PmergeMe::sortList(std::list<int>& lst) {
	mergeInsertSort(lst);
}