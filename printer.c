#include "shell.h"

/**
 * my_putchar - putchar
 * @c: charachter
 * Return: prints outpuy
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * my_puts - puts
 * @str: string
*/
void my_puts(char *str)
{
	while (*str != '\0')
	{
		my_putchar(*str);
		str++;
	}
	my_putchar('\n');
}

/**
 * my_print - print
 * @str: string
*/
void my_print(char *str)
{
	while (*str != '\0')
	{
		my_putchar(*str);
		str++;
	}
}
