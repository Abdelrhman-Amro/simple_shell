#include "shell.h"

/**
 * my_getenv - get variable from environment
 * @vr: variable to search for
 * Return: pointer to variable if exists
*/
char *get_env(char *vr)
{
	int i = 0, j;

	if (vr == NULL || vr[0] == '\0' || str_chr(vr, '=') != NULL)
		return (NULL);
	while (environ[i])
	{
		j = 0;
		while (vr[j] != '\0' && environ[i][j] != '=' && (environ[i][j] == vr[j]))
			j++;
		if (vr[j] == '\0' && environ[i][j] == '=')
			return (environ[i] + j + 1);
		i++;
	}
	return (NULL);
}

/**
 * check_pth - check if path exist
 * @h: head of the list
 * @com: command to search for its path
 * Return: string of complete path
*/
char *check_pth(d_list *h, char *com)
{
	char *pth;
	int len, i, j;

	while (h)
	{
		len = str_len(com) + h->len + 2;
		pth = (char *) malloc(sizeof(char) * len);
		for (i = 0; i < h->len; i++)
			pth[i] = h->dir[i];
		pth[i] = '/';
		i++;
		for (j = 0; i < len - 1; i++, j++)
			pth[i] = com[j];
		pth[i] = '\0';
		if (!access(pth, F_OK | X_OK))
			return (pth);/*you should free path*/
		h = h->next;
		free(pth);
	}
	return (NULL);
}
