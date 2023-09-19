#include "shell.h"

/**
 * my_exit - exit
 * @words: args
 * @h: head
 * Return: integer
*/
int my_exit(char **words, list_d *h)
{
	if (h != NULL)
		free_list(h);
	if (words[1])
	{
		return (atoi(words[1]));
	}
	else
	{
		return (0);
	}
}

/**
 * my_env - print env
 * Return: integer
*/
int my_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		my_puts(environ[i]);

	return (-1);
}
