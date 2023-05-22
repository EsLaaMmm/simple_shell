#include "shell.h"

/**
 * exit_shell - Built-in function that exits the shell
 * @args: Arguments passed to the function
 * Return: 0 if successful, or 1 if there is an error
 */
int exit_shell(char **args)
{
	if (args[1] != NULL)
	{
		char *endptr;
		long exit_code = strtol(args[1], &endptr, 10);

		if (*endptr != '\0' || exit_code > INT_MAX || exit_code < INT_MIN)
		{
			fprintf(stderr, "Error: Invalid exit code\n");
			return (1);
		}
		exit((int) exit_code);
	}
	else
	{
		exit(0);
	}
}
