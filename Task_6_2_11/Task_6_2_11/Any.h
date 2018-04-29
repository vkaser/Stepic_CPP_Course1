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

	ValueHolder * clone() const {
		return new ValueHolder(data_);
	}

	T data_;
};

class Any
{
public:

	Any() : held_(0) { }

	template <typename T>
	Any(const T& t) : held_(new ValueHolder<T>(t)) { }

	~Any() { delete held_; }

	Any(const Any& other) : held_(other.held_ ? other.held_->clone() : 0) { }

	Any & operator=(Any const & other) {
		if (this != &other) {
			if (this->held_)
				delete held_;
			held_ = 0;
			if (other.held_)
				held_ = other.held_->clone();
		}
		return *this;
	}

	template<class Other>
	Any & operator=(const Other & other) {
		if (this->held_)
			delete held_;
		held_ = 0;
		if (other)
			held_ = new ValueHolder<Other>(other);
		return *this;
	}

	template<typename Type>
	Type * cast() {
		return dynamic_cast<ValueHolder<Type> *>(held_) ? &(dynamic_cast<ValueHolder<Type> *>(held_)->data_) : 0;

		/*ValueHolder<Type> * ptr = dynamic_cast<ValueHolder<Type> *>(held_);
		if (ptr)
			return &(dynamic_cast<ValueHolder<Type> *>(held_)->data_);
		else
			return 0;*/
	}
private:
	ICloneable * held_;
};