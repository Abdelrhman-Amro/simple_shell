#include "shell.h"

/**
 * split - split string into words according to delimeters
 * @l: line of strin
 * @dlm: delimeters
 * Return: array of words
 */
char **split(char *l, char *dlm)
{
	char *cp, *wrd, **wrds;
	int i;

	if (l == NULL)
		return (NULL);
	cp = str_dup(l);
	wrd = strtok(cp, dlm);
	if (wrd == NULL)
	{
		free(cp);
		return (NULL);
	}
	wrds = (char **)malloc(sizeof(char *) * 64);
	for (i = 0; wrd != NULL; i++)
	{
		wrds[i] = wrd;
		wrd = strtok(NULL, dlm);
	}
	wrds[i] = NULL;
	return (wrds);
}
