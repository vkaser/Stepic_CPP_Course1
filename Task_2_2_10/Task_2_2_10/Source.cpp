#include<iostream>
using namespace std;

void rev(int a) {
	int b;
	if (a != 0) {
		cin >> b;
		rev(b);
		cout << a << " ";
	}
}

int main() {
	int a;
	cin >> a;
	rev(a);
	return 0;
}