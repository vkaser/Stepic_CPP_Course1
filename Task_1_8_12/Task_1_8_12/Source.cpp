#include <iostream>
using namespace std;

int main()
{
	bool T = false;
	char c = '\0';
	while (cin.get(c))
	{
		if (c == ' ' && !T)
		{
			T = true;
			cout << c;
		}
		else if (c == ' ' && T)
			continue;
		else
		{
			cout << c;
			T = false;
		}
	}

	return 0;
}