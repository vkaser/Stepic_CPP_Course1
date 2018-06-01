#include <iostream>
using namespace std;

char* resize(const char* str, unsigned size, unsigned new_size)
{
	char* new_str = new char[new_size];
	for (int i = 0; i < new_size && i < size; i++)
	{
		*(new_str + i) = *(str + i);
	}
	delete[] str;
	return new_str;
}

char* getline()
{
	char c;
	const unsigned ALLOC_SIZE = 64;
	unsigned i = 0, size = 64;

	char* str = new char[size];
	while (cin.get(c) && c != '\n')
	{
		if (i == size)
			str = resize(str, i, size += ALLOC_SIZE);
		str[i++] = c;
	}


	str[i] = '\0';

	return str;
}