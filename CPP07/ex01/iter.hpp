#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* array, int length, F function) {
	for (int i = 0; i < length; i++)
		function(array[i]);
}