#include "shell.h"

/**
 * my_getenv - getenv
 * @var: variable
 * Return: char
*/
char *my_getenv(char *var)
{
	int i = 0, j;

	if (var == NULL || var[0] == '\0' || my_strchr(var, '=') != NULL)
		return (NULL);

	while (environ[i])
	{
		j = 0;
		while (var[j] != '\0' && environ[i][j] != '=' && (environ[i][j] == var[j]))
			j++;
		if (var[j] == '\0' && environ[i][j] == '=')
			return (environ[i] + j + 1);
		i++;
	}

	return (NULL);
}

/**
 * find_path - find
 * @h: head
 * @cmd: command
 * Return: char
*/
char *find_path(list_d *h, char *cmd)
{
	char *path;
	int sz, i, j;

	while (h)
	{
		sz = my_strlen(cmd) + h->len + 2;
		path = (char *) malloc(sizeof(char) * sz);

		for (i = 0; i < h->len; i++)
			path[i] = h->dir[i];
		path[i] = '/';
		i++;
		for (j = 0; i < sz - 1; i++, j++)
			path[i] = cmd[j];
		path[i] = '\0';

		if (!access(path, F_OK | X_OK))
			return (path);/*you should free path*/

		h = h->next;
		free(path);
	}

	return (NULL);
}
