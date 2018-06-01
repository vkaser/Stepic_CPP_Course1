char *resize(const char *str, unsigned size, unsigned new_size)
{
	const char *pstr = str;
	char *new_str = new char[new_size];
	char *pnew_str = new_str;
	size = size < new_size ? size : new_size;
	while (size--) {
		*pnew_str = *pstr;
		pnew_str++;
		pstr++;
	}
	delete[] str;
	return new_str;
}