struct Rational
{
	Rational(int numerator = 0, int denominator = 1);

	void add(Rational rational);
	void sub(Rational rational);
	void mul(Rational rational);
	void div(Rational rational);

	void neg();
	void inv();
	double to_double() const;

	Rational & operator+=(Rational const&);
	Rational & operator-=(Rational const&);
	Rational & operator*=(Rational const&);
	Rational & operator/=(Rational const&);

	Rational & operator+=(int const&);
	Rational & operator-=(int const&);
	Rational & operator*=(int const&);
	Rational & operator/=(int const&);

	Rational operator+() const;
	Rational operator-() const;

private:
	int numerator_;
	int denominator_;
};

Rational & Rational::operator+=(Rational const& rational) {
	this->add(rational);
	return *this;
}

Rational & Rational::operator-=(Rational const& rational) {
	this->sub(rational);
	return *this;
}

Rational & Rational::operator*=(Rational const& rational) {
	this->mul(rational);
	return *this;
}

Rational & Rational::operator/=(Rational const& rational) {
	this->div(rational);
	return *this;
}

Rational & Rational::operator+=(int const& rational) {
	this->add(Rational(rational, 1));
	return *this;
}

Rational & Rational::operator-=(int const& rational) {
	this->sub(Rational(rational, 1));
	return *this;
}

Rational & Rational::operator*=(int const& rational) {
	this->mul(Rational(rational, 1));
	return *this;
}

Rational & Rational::operator/=(int const& rational) {
	this->div(Rational(rational, 1));
	return *this;
}

Rational Rational::operator+() const {
	return Rational(this->numerator_, this->denominator_);
}

Rational Rational::operator-() const {
	return Rational(-this->numerator_, this->denominator_);
}