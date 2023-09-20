#include "shell.h"

/**
 * ex_it - exit from the project
 * @wrds: Arguments
 * @h: head of the list
 * Return: arg[1] or 0
*/
int ex_it(char **wrds, d_list *h)
{
	if (h != NULL)
		free_L(h);
	if (wrds[1])
	{
		return (a_to_i(wrds[1]));
	}
	else
	{
		return (0);
	}
}

/**
 * en_v - print evironment
 * Return: -1
*/
int en_v(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		print_newline(environ[i]);
	return (-1);
}
