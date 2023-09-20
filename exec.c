#include "shell.h"

/**
 * if_built_in - check if command built in
 * @com: command to check
 * Return: true or false
*/
int if_built_in(char *com)
{
	if (str_cmp(com, "exit") == 0)
		return (1);
	else if (str_cmp(com, "env") == 0)
		return (1);
	else
		return (0);
}

/**
 * exec_built_in - Execute built-in commands
 * @wrds: Argument to pass
 * @h: head of the list
 * Return: the return value of built in
*/
int exec_built_in(char **wrds, d_list *h)
{
	if (str_cmp(wrds[0], "exit") == 0)
		return (ex_it(wrds, h));
	else
		return (en_v());
}

/**
 * exec_com - Execute commands
 * @argus: arguments to execute
 * Return: -1 if success
*/
int exec_com(char **argus)
{
	char **enviro = NULL;
	pid_t idn;/*idn -> id number*/
	int stat;

	idn = fork();
	if (idn ==  0)
	{
		if (execve(argus[0], argus, enviro) == -1)
		{
			perror("Error in execve: ");
			exit(EXIT_FAILURE);
		}
	}
	else if (idn < 0)
	{
		perror("Error in fork: ");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(idn, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}

	return (-1);
}
