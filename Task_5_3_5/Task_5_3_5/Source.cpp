struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{
	explicit SharedPtr(Expression *);
	~SharedPtr();
	SharedPtr(const SharedPtr &);
	SharedPtr& operator=(const SharedPtr &);
	void swap(SharedPtr &);
	Expression* get() const;
	void reset(Expression *ptr);
	Expression& operator*() const;
	Expression* operator->() const;
private:
	Expression * ptr_;
	size_t * ctr_;
	void free();
};

SharedPtr::SharedPtr(Expression *ptr = 0) : ptr_(ptr), ctr_(0) {
	if (ptr_) ctr_ = new size_t(1);
}

SharedPtr::~SharedPtr() {
	free();
}

SharedPtr::SharedPtr(const SharedPtr & other) : ptr_(other.ptr_), ctr_(other.ctr_) {
	if (ctr_)
		++*ctr_;
}

SharedPtr& SharedPtr::operator=(const SharedPtr & other) {
	if (this != &other && other.ptr_) {
		SharedPtr(other).swap(*this);
	}
	return *this;
}

void SharedPtr::swap(SharedPtr & ptr) {
	Expression * temp_ptr = ptr.ptr_;
	ptr.ptr_ = ptr_;
	ptr_ = temp_ptr;

	size_t * temp_ctr = ptr.ctr_;
	ptr.ctr_ = ctr_;
	ctr_ = temp_ctr;
}

Expression* SharedPtr::get() const {
	return ptr_;
}

void SharedPtr::reset(Expression *ptr = 0) {
	if (ptr_ != ptr) {
		free();
		ptr_ = ptr;
		ctr_ = new std::size_t(1);
	}
}

Expression& SharedPtr::operator*() const {
	return *ptr_;
}

Expression* SharedPtr::operator->() const {
	return ptr_;
}

void SharedPtr::free() {
	if (ptr_ && --*ctr_ == 0) {
		delete ptr_;
		delete ctr_;
	}
	else if (!ptr_) {
		delete ctr_;
	}
	ctr_ = 0;
	ptr_ = 0;
}