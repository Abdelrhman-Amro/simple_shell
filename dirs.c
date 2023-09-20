#include "shell.h"

/**
 * Dirs - Build list of dirs that in path variable
 * Return: head of the list
*/
d_list *Dirs()
{
	int i;
	d_list *H = NULL;/*H -> Head*/
	char **D = Parse(my_getenv("PATH"), pth_DELIM);/*D -> Dirs*/

	if (D == NULL)
		return (NULL);
	for (i = 0; D[i] != NULL; i++)
		add_D(&H, D[i]);

	free(D[0]);
	free(D);

	return (H);
}

/**
 * add_D - insert node at the start of  the list
 * @h: Head of the list
 * @s: string(dir) to add to the list
 * Return: new node
*/
d_list *add_D(d_list **h, char *s)
{
	d_list *new_node = malloc(sizeof(d_list));
	int l = str_len(s);

	new_node->len = l;
	new_node->dir = str_dup(s);
	new_node->next = *h;
	*h = new_node;

	return (new_node);
}

/**
 * free_L - free list
 * @h: Head of the list
*/
void free_L(d_list *h)
{
	d_list *tmp;

	while (h)
	{
		tmp = h;
		h = h->next;
		free(tmp->dir);
		free(tmp);
	}
}
