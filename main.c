#include "shell.h"

/**
 * executor - Execute command
 * @wrds: Argument (array of strings)
 * @l: line of the argument (string)
 * @h: head of the list
 * Return: Status (number point to the status of the function)
*/
int executor(char **wrds, char *l, d_list *h)
{
	int stat = -1, shft = 0, f;/*f -> flag*/
	char *pth = NULL, *tmp;

	shft = str_spn(l, cmd_DELIM);
	if (wrds != NULL)
	{
		f = if_built_in(wrds[0]);
		if (h != NULL)
			pth = check_pth(h, wrds[0]);
		if (str_chr(wrds[0], '/'))
			stat = exec_com(wrds);
		else if (f)
			stat = exec_built_in(wrds, h);
		else if (pth)
		{
			tmp = wrds[0];
			wrds[0] = pth;
			stat = exec_com(wrds);
			free(tmp - shft);
			shft = 0;
		}
		else
			perror("Not Found--->");
		free(wrds[0] - shft);
		free(wrds);
	}
	return (stat);
}

/**
 * active_mod - work in interactive mode
*/
void active_mod(void)
{
	char *prmpt = "($) ", *l, **wrds;
	int stat;
	struct dirs_list *h;

	h = Dirs();
	while (1)
	{
		print_no_newline(prmpt);
		l = take_line(h);
		wrds = split(l, cmd_DELIM);
		stat = executor(wrds, l, h);
		free(l);
		if (stat >= 0)
			exit(stat);
	}
}

/**
 * non_active_mod - Work in non_interactive mode
*/
void non_active_mod(void)
{
	char *l, **wrds;
	int stat;
	struct dirs_list *h;

	h = Dirs();
	while (1)
	{
		l = take_line(h);
		wrds = split(l, cmd_DELIM);
		stat = executor(wrds, l, h);
		free(l);
		if (stat >= 0)
			exit(stat);
	}
}

/**
 * main - Entry point
 * Return: (0)
*/
int main(void)
{
		if (isatty(STDIN_FILENO))
			active_mod();
		else
			non_active_mod();
		return (0);
}
