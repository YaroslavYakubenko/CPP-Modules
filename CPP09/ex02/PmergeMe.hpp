#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

class PmergeMe {
public:
	static void sortVector(std::vector<int>& vec);
	static void sortList(std::list<int>& lst);
};