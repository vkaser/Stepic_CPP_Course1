#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{
	String(size_t n, char c)
		: size(n)
		, str(new char[n + 1])
	{
		str[n] = '\0';
		while (n)
			str[--n] = c;
	}

	~String()
	{
		delete[] str;
	}

	size_t size;
	char *str;
};