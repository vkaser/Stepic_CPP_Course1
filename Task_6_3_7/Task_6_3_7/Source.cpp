#include <iostream>
#include "SameType.h"

struct Dummy { };
typedef int type;

int main() {
	std::cout << SameType<int, int>::value << std::endl;
	std::cout << SameType<int, type>::value << std::endl;
	std::cout << SameType<int, int&>::value << std::endl;
	std::cout << SameType<Dummy, Dummy>::value << std::endl; 
	std::cout << SameType<int, const int>::value << std::endl;
	return 0;
}