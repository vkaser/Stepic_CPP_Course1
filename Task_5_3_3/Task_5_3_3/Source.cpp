struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr
{
	explicit ScopedPtr(Expression *);
	~ScopedPtr();
	Expression* get() const;
	Expression* release();
	void reset(Expression *);
	Expression& operator*() const;
	Expression* operator->() const;


private:
	ScopedPtr(const ScopedPtr&);
	ScopedPtr& operator=(const ScopedPtr&);

	Expression *ptr_;
};

ScopedPtr::ScopedPtr(Expression *ptr = 0) : ptr_(ptr)
{}

ScopedPtr::~ScopedPtr() {
	delete ptr_;
}

Expression* ScopedPtr::get() const {
	return ptr_;
}

Expression* ScopedPtr::release() {
	Expression * pointer = ptr_;
	ptr_ = nullptr;
	return pointer;
}

void ScopedPtr::reset(Expression *ptr = 0) {
	delete ptr_;
	ptr_ = ptr;
}

Expression& ScopedPtr::operator*() const {
	return *ptr_;
}

Expression* ScopedPtr::operator->() const {
	return ptr_;
}
