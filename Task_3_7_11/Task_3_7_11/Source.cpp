#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

	String &operator=(const String &other) {
		String(other).swap(*this);
		return *this;
	}

	void append(const String &other);

	void swap(String& s) {
		std::swap(size, s.size);
		std::swap(str, s.str);
	}

	size_t size;
	char *str;
};