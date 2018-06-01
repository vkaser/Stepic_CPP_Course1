void rotate(int a[], unsigned size, int shift)
{
	int *p = a;
	shift = shift % size;
	int *q = &a[size - 1];
	int t = 0;
	for (int i = 0; i < shift; i++)
	{
		t = *q;
		*q = *p;
		int j = 0;
		while (j < size - 2)
		{
			*p = *(p + 1);
			p++;
			j++;
		}
		*p = t;
		p = a;
		q = &a[size - 1];
	}

}