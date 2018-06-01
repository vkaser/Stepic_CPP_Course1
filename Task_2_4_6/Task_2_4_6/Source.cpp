unsigned strlen(const char *str)
{
	const char *pstr = str;
	while (*str) str++;
	return (str - pstr);
}