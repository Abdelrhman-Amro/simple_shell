#include "shell.h"

/**
 * str_len - calculate the length of the string
 * @s: pointer to string
 * Return: Length of the string
 */
size_t str_len(const char *s)
{
	size_t i = 0;

	for (i = 0; s[i] != '\0'; i++)
		i++;
	return (i);
}

/**
 * str_chr - search for char in string
 * @s: pointer to string
 * @c: Character to search for
 * Return: pointer to character or null
 */
char *str_chr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

/**
 * str_cpy - copy a string from s to d
 * @s: pointer to source
 * @d: pointer to destination
 * Return: pointer to d
 */
char *str_cpy(char *d, const char *s)
{
	int i = 0;

	if (d == NULL)
		return (NULL);
	if (d == s)
		return (d);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/**
 * str_dup - Duplicate the string
 * @s: string to duplicate
 * Return: pointer to duplicated string
*/
char *str_dup(const char *s)
{
	size_t ln = str_len(s);
	char *dp = malloc(sizeof(char) * (ln + 1));

	if (s == NULL)
		return (NULL);
	if (dp == NULL)
		return (NULL);
	str_cpy(dp, s);
	return (dp);
}

/**
 * str_cmp - Compare between two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0if s1=s2 1if s1>s2 -1ifs2>s1
*/
int str_cmp(char *s1, char *s2)
{
	int flag = 0;

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	flag = (*s1 == *s2) ? 0 : (*s1 > *s2) ? 1 : -1;

	return (flag);
}
