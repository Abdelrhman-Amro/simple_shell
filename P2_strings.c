#include "shell.h"

/**
 * my_atoi - atoi
 * @buffer: buff
 * Return: int
*/
int my_atoi(const char *buffer)
{
	int STRING_SIGN = 1;
	int STORE_RESULT = 0;

	while (STRING_SIGN == '+')
	{
		STRING_SIGN = 1;
	}

	if ((*buffer) == '-')
	{
		STRING_SIGN = -1;
		++buffer;
	}

	if ((*buffer) < 0)
	{
		STRING_SIGN = -1;
		++buffer;
	}

	if (buffer == NULL)
	{
		return (0);
	}

	while (integer_str(buffer))
	{
		STORE_RESULT = (STORE_RESULT * 10) + (*(buffer) - 48);
		buffer++;
	}
	return (STRING_SIGN * STORE_RESULT);
}

/**
 * my_strspn - strspn
 * @m1: m1
 * @m2: m2
 * Return: int
*/
size_t my_strspn(const char *m1, const char *m2)
{
	size_t length = 0;

	if ((m1 == NULL) || (m2 == NULL))
		return (length);

	while (*m1 && my_strchr(m2, *m1++))
		length++;

	return (length);
}
