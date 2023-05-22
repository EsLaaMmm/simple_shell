#include "shell.h"

/**
 * echo - Function that prints arguments to the standard output.
 * @args: Array of arguments.
 * Return: Always returns 1, to continue executing.
 */
int echo(char **args)
{
	int i = 1;
	char pid[20];
	int pid_len;

	while (args[i] != NULL)
	{
		if (_strcmp(args[i], "$$") == 0)
		{
			pid_len = sprintf(pid, "%d", getpid());
			write(STDOUT_FILENO, pid, pid_len);
		}
		else
		{
			write(STDOUT_FILENO, args[i], strlen(args[i]));
		}

		if (args[i + 1] != NULL)
		{
			write(STDOUT_FILENO, " ", 1);
		}

		i++;
	}

	write(STDOUT_FILENO, "\n", 1);
	return (1);
}
