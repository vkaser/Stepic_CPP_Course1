#include<iostream>

template <typename T, size_t size>
size_t array_size(T (&a)[size]) {
	return size;
}

int main() {
	int ints[] = { 1, 2, 3, 4 };
	int *iptr = ints;
	double doubles[] = { 3.14 };
	std::cout << array_size(ints) << std::endl;
	std::cout << array_size(doubles) << std::endl;
	//array_size(iptr); // Compilation error
	return 0;
}