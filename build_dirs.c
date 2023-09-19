#include "shell.h"

/**
 * build_dirs - build dirs
 * Return: list
*/
list_d *build_dirs()
{
	int i;
	list_d *head = NULL;
	char **dirs = Parse(my_getenv("PATH"), pth_DELIM);

	if (dirs == NULL)
		return (NULL);
	for (i = 0; dirs[i] != NULL; i++)
		add_dir(&head, dirs[i]);

	free(dirs[0]);
	free(dirs);

	return (head);
}

/**
 * add_dirs - add dirs
 * @head: head list
 * @str: dir list
 * Return: list
*/
list_d *add_dir(list_d **head, char *str)
{
	list_d *New = malloc(sizeof(list_d));
	int l = my_strlen(str);

	New->len = l;
	New->dir = my_strdup(str);
	New->next = *head;
	*head = New;

	return (New);
}

/**
 * free_list - free
 * @h: head list
 * Return: list
*/
void free_list(list_d *h)
{
	list_d *temp;

	while (h)
	{
		temp = h;
		h = h->next;
		free(temp->dir);
		free(temp);
	}
}
