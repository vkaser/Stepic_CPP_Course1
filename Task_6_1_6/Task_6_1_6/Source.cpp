#include <cstddef>
#include <algorithm>

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