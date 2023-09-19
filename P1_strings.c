#include "shell.h"

/**
 * my_strlen - length
 * @m : the pointer of the string
 * Return: returns the value of length of a string
 */
size_t my_strlen(const char *m)
{
	size_t ln = 0;

	while (*m != '\0')
	{
		ln++;
		m++;
	}

	return (ln);
}

/**
 * my_strchr - strchr
 * @str: the pointrr for the inpute string
 * @ch: it is the character to be occurrend
 * Return: pointer
 */
char *my_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}

	return (NULL);
}

/**
 * my_strcpy - copy a string
 * @src: pointer for the source
 * @dst: pointer to the destination
 * Return: pointer to the destination
 */
char *my_strcpy(char *dst, const char *src)
{
	int m = 0;

	if (dst == NULL)
		return (NULL);

	if (dst == src)
		return (dst);

	while (src[m] != '\0')
	{
		dst[m] = src[m];
		m++;
	}

	dst[m] = '\0';

	return (dst);
}

/**
 * my_strdup - dup
 * @src: src
 * Return: pointer
*/
char *my_strdup(const char *src)
{
	size_t ln = my_strlen(src);
	char *dup = (char *)malloc((ln + 1) * sizeof(char));

	if (src == NULL)
		return (NULL);

	if (dup == NULL)
		return (NULL);

	my_strcpy(dup, src);

	return (dup);
}

/**
 * my_strcmp - compare
 * @m1: s1
 * @m2: s2
 * Return: int
*/
int my_strcmp(char *m1, char *m2)
{
	int cmp_st = 0;

	while ((*m1 != '\0' && *m2 != '\0') && *m1 == *m2)
	{
		m1++;
		m2++;
	}
	cmp_st = (*m1 == *m2) ? 0 : (*m1 > *m2) ? 1 : -1;

	return (cmp_st);
}
