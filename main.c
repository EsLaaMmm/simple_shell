#include "shell.h"

/**
 * prompt - Displays shell prompt
 *
 * Return: 0
 */
void prompt(void)
{
	char *msg = "cisfun$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, msg, strlen(msg));
		fflush(stdout);
	}
}

/**
 * main - Entry Point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Success
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	if (argc > 1)
	{
		input(argv[1]);
		return (EXIT_SUCCESS);
	}
	do {
		prompt();
		line = read_line();
		args = parse_input(line);
		status = execute_command(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
