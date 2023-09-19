#include "shell.h"

/**
 * read_line - read
 * @h: head
 * Return: char
*/
char *read_line(list_d *h)
{
	char *line = NULL;
	size_t n = 0;

	if (getline(&line, &n, stdin) == EOF)
	{
		free(line);
		if (h != NULL)
			free_list(h);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
