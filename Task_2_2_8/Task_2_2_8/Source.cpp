unsigned gcd(unsigned a, unsigned b)
{
	return b ? gcd(b, a%b) : a;
}
