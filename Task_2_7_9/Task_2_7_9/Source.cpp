int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
	int i = 0, j = 0;
	int **tr = new int *[cols];
	tr[0] = new int[cols * rows];
	for (i = 1; i < cols; i++)
		tr[i] = tr[i - 1] + rows;
	for (i = 0; i < cols; i++)
		for (j = 0; j < rows; j++)
			tr[i][j] = m[j][i];
	return tr;
}