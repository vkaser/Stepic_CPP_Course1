#include <algorithm>
#include <new> //for placement new

template <typename T>
class Array
{
public:
	explicit Array(size_t size, const T& value = T()) : size_(size) {
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(value);
	}

	Array() : size_(0), data_(0)
	{}

	Array(const Array & other) : size_(other.size_) {
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i < size_; ++i)
			new (data_ + i) T(*(other.data_ + i));
	}

	~Array() {
		for (size_t i = 0; i < size_; ++i)
			data_[i].~T();
		operator delete[](data_);
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