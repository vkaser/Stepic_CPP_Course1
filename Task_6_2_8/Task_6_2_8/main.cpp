#include <cstddef>
#include<algorithm>
#include<new>

template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T()) : size_(size), data_(new T[size]) {
		for (size_t i = 0; i < size; ++i)
			data_[i] = value;
	}

	Array(const Array & other) : size_(other.size_), data_(new T[other.size_]) {
		for (size_t i = 0; i < other.size_; ++i)
			data_[i] = other.data_[i];
	}

	~Array() {
		delete[] data_;
	}

	void swap(Array & arr) {
		std::swap(size_, arr.size_);
		std::swap(data_, arr.data_);
	}

	Array& operator=(Array const & other) {
		if (this != &other)
			Array(other).swap(*this);
		return *this;
	}

	size_t size() const { return size_; }

	T& operator[](size_t i) { return data_[i]; }
	const T& operator[](size_t i) const { return data_[i]; }

private:
	T * data_;
	size_t size_;
};

template<typename Type, typename Comp>
Type minimum(Array<Type>& a, Comp less) {
	if (a.size() == 0) return 0;
	Type min = a[0];
	for (int i = 1; i < a.size(); ++i) {
		if (less(a[i], min))
			min = a[i];
	}
	return min;
}

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

int main() {
	Array<int> ints(3);
	ints[0] = 10;
	ints[1] = 2;
	ints[2] = 15;
	int min = minimum(ints, less);
	int max = minimum(ints, Greater());
	return 0;
}