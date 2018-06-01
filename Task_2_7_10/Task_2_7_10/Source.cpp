void swap_min(int *m[], unsigned rows, unsigned cols)
{
	int i = 0, j = 0, min = 0, row = 0, *p = 0;
	min = m[0][0];
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			if (min > m[i][j])
			{
				min = m[i][j];
				row = i;
			}
	if (row != 0)
	{
		p = m[0];
		m[0] = m[row];
		m[row] = p;
	}

	p = 0;
}