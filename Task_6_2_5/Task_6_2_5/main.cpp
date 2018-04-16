#include<cstddef>

template<typename T, typename U>
void copy_n(T * t, U * u, size_t n) {
	while (n--)
		*t++ = (T)*u++;
}

int main() {
	int ints[] = { 1, 2, 3, 4 };
	double doubles[4] = {};
	copy_n(doubles, ints, 4);
	return 0;
}