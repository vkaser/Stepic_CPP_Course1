#include<iostream>
using namespace std;

int strstr1(const char *text, const char *pattern)
{
	const char *start = text;
	const char *start_text = text;
	const char *start_pat = pattern;
	do
	{
		for (start = text, start_pat = pattern;
			*start_pat && *start && *start == *start_pat;
			start++, start_pat++);
		if (!*start_pat)
			return text - start_text;
		text++;
	} while (*text);
	return -1;
}

int main() {
	cout << strstr1("Hello, World!", "!") << endl;
	return 0;
}