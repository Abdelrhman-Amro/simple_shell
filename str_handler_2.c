#include "shell.h"

/**
 * a_to_i - Convetr string to integer
 * @s: string to convert
 * Return: integer
*/
int a_to_i(const char *s)
{
	int sign = 1;
	int res = 0;

	if (s == NULL)
		return (0);
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	while (check_if_num(*s))
	{
		res = (res * 10) + (*s - 48);
		s++;
	}
	return (sign * res);
}

/**
 * str_spn - calculate characters in s2 are in the initial segment of s1
 * @s1: Original string
 * @s2: Substring
 * Return: Number of characters accepted in the initial segment of s1
*/
size_t str_spn(const char *s1, const char *s2)
{
	size_t ln = 0;

	if (s1 == NULL || s2 == NULL)
		return (ln);
	while (*s1 && str_chr(s2, *s1++))
		ln++;
	return (ln);
}
