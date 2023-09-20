#include "shell.h"

/**
 * take_line - read the line
 * @h: head of the list
 * Return: poiter to the line
*/
char *take_line(d_list *h)
{
	char *l = NULL;/*l -> line*/
	size_t n = 0;

	if (getline(&l, &n, stdin) == EOF)
	{
		free(l);
		if (h != NULL)
			free_L(h);
		exit(EXIT_SUCCESS);
	}
	return (l);
}
