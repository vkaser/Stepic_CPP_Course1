#pragma once
struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {
	ValueHolder(const T & data) : data_(data)
	{}

	ValueHolder * clone() const{
		return new ValueHolder(data_);
	}

	T data_;
};
