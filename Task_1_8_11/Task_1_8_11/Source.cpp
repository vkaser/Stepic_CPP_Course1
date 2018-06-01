#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	double D, x1, x2;
	D = b * b - 4 * a * c;
	if (D > 0)
	{
		x1 = ((-b) + sqrt(D)) / (2 * a);
		x2 = ((-b) - sqrt(D)) / (2 * a);
	}
	else if (D == 0)
	{
		x1 = (-b) / (2 * a);
		x2 = x1;
	}
	else
	{
		cout << "No real roots";
		return 0;
	}
	cout << x1 << " " << x2;
	return 0;
}