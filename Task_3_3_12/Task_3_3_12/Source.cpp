#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

	void append(String &other) {
		char *new_str = strcat(strcpy(new char[(size = size + other.size) + 1], str), other.str);
		delete[] str;
		str = new_str;
	}

	size_t size;
	char *str;
};