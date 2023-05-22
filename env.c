#include "shell.h"

/**
 * set_environment - Implement setenv command
 * @args: Arguments
 * Return: 0 on success, or 1 on failure
 */
int set_environment(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("setenv");
		return (1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}

/**
 * unset_environment - Implements unsetenv command
 * @args: Arguments
 * Return: 0 on success, or 1 on failure.
 */
int unset_environment(char **args)
{
	if (args[1] == NULL)
	{
		perror("unsetenv");
		return (1);
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}
