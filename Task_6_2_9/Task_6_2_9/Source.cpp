#include "Array.h"
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream &os, const Array<T>& array) {
	for (size_t i = 0; i < array.size(); ++i)
		os << array[i] << " ";
	return os;
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) { 
	out << array;
}

int main() {
	Array<int> ints(2, 0);
	ints[0] = 10;
	ints[1] = 20;
	flatten(ints, std::cout);
	std::cout << std::endl;
	Array< Array<int> > array_of_ints(2, ints);
	flatten(array_of_ints, std::cout);

	Array<double> doubles(10, 0.0);
	flatten(doubles, std::cout);
	return 0;
}