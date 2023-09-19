#include "shell.h"

/**
 * Built_in - check
 * @cmd: command
 * Return: integer
*/
int Built_in(char *cmd)
{
	if (my_strcmp(cmd, "exit") == 0)
		return (1);
	else if (my_strcmp(cmd, "env") == 0)
		return (1);
	else
		return (0);
}

/**
 * Ex_Built_in - Execute
 * @words: arguments
 * @h: head
 * Return: integer
*/
int Ex_Built_in(char **words, list_d *h)
{
	if (my_strcmp(words[0], "exit") == 0)
		return (my_exit(words, h));
	else
		return (my_env());
}

/**
 * Execute - Execution
 * @args: arguments
 * Return: integer
*/
int Execute(char **args)
{
	char **en = NULL;
	pid_t id;
	int st;

	id = fork();
	if (id ==  0)
	{
		if (execve(args[0], args, en) == -1)
		{
			perror("Error in execve: ");
			exit(EXIT_FAILURE);
		}
	}
	else if (id < 0)
	{
		perror("Error in fork: ");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(id, &st, WUNTRACED);
		} while (!WIFEXITED(st) && !WIFSIGNALED(st));
	}

	return (-1);
}
