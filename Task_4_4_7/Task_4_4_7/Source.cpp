bool check_equals(Expression const *left, Expression const *right)
{
	int *a1 = (int *)left;
	int *a2 = (int *)right;
	return *a1 == *a2;
}