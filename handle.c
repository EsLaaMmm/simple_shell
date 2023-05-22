#include "shell.h"

/**
 * handle_error - Prints error message exits with failure status
 * @message: Error message to be printed
 */
void handle_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

/**
 * handle_alias - Implements the alias built-in command
 * @args: Array of strings containing the command and its arguments
 * Return: Always returns 0
 */
int handle_alias(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		char *msg_error = "alias: missing arguments\n";

		write(STDERR_FILENO, msg_error, strlen(msg_error));
		return (1);
	}

	return (0);
}
