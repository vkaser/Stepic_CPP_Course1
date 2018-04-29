#include<iostream>
#include "Any.h"
using namespace std;

int main() {
	Any empty;
	Any i(10);
	Any copy(i);

	empty = copy;
	empty = 0;

	int *iptr = i.cast<int>();
	char *cptr = i.cast<char>();

	Any empty2;
	int *p = empty2.cast<int>();

	return 0;
}