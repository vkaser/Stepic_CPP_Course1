#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> c;
	while (c)
	{
		cin >> a >> b;
		cout << (a + b) << endl;
		--c;
	}

	return 0;
}