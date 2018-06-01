int power(int x, unsigned p) {
	int answer = 1;
	while (p>0)
	{
		answer = x * answer;
		p--;
	}
	return answer;
}