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

	Rational& operator+=(Rational rational);
	Rational& operator-=(Rational rational);
	Rational& operator*=(Rational rational);
	Rational& operator/=(Rational rational);

	Rational operator-() const;
	Rational operator+() const;

	Rational operator+(Rational const&) const;
	Rational operator-(Rational const&) const;
	Rational operator*(Rational const&) const;
	Rational operator/(Rational const&) const;

	Rational operator+(int const&) const;
	Rational operator-(int const&) const;
	Rational operator*(int const&) const;
	Rational operator/(int const&) const;

private:
	int numerator_;
	int denominator_;
};

Rational Rational::operator+(Rational const& rational) const {
	Rational t(this->numerator_, this->denominator_);
	t.add(rational);
	return t;
}

Rational Rational::operator-(Rational const& rational) const {
	Rational t(this->numerator_, this->denominator_);
	t.sub(rational);
	return t;
}

Rational Rational::operator*(Rational const& rational) const {
	Rational t(this->numerator_, this->denominator_);
	t.mul(rational);
	return t;
}

Rational Rational::operator/(Rational const& rational) const {
	Rational t(this->numerator_, this->denominator_);
	t.div(rational);
	return t;
}

Rational Rational::operator+(int const& number) const {
	Rational t(number, 1);
	t.add(*this);
	return t;
}

Rational Rational::operator-(int const& number) const {
	Rational t(this->numerator_, this->denominator_);
	t.sub(Rational(number, 1));
	return t;
}

Rational Rational::operator*(int const& number) const {
	Rational t(this->numerator_, this->denominator_);
	t.mul(Rational(number, 1));
	return t;
}

Rational Rational::operator/(int const& number) const {
	Rational t(this->numerator_, this->denominator_);
	t.div(Rational(number, 1));
	return t;
}

Rational operator+(int const& number, Rational const & rational) {
	Rational t(number, 1);
	t.add(rational);
	return t;
}

Rational operator-(int const& number, Rational const & rational) {
	Rational t(number, 1);
	t.sub(rational);
	return t;
}

Rational operator*(int const& number, Rational const & rational) {
	Rational t(number, 1);
	t.mul(rational);
	return t;
}

Rational operator/(int const& number, Rational const & rational) {
	Rational t(number, 1);
	t.div(rational);
	return t;
}