#include <iostream>

using namespace std;

int log(int a);

int main()
{
	int a = 0, lg = 0;
	cin >> a;
	while (a)
	{
		cin >> lg;
		cout << log(lg) << "\n";
		--a;
	}
	return 0;
}

int log(int a)
{
	int c = 0;
	while (a != 1)
	{
		a /= 2;
		++c;
	}
	return c;
}