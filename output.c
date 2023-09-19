#include "shell.h"

/**
 * print_char - print character
 * @c: charachter to print
 * Return: write -> output
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_newline - print string with new line
 * @s: string to print
*/
void print_newline(char *s)
{
	while (*s != '\0')
	{
		print_char(*s);
		s++;
	}
	print_char('\n');
}

/**
 * print_no_newline - print string without new line
 * @s: string to print
*/
void print_no_newline(char *s)
{
	while (*s != '\0')
	{
		print_char(*s);
		s++;
	}
}
