#include "shell.h"

/**
 * execute_command - Function that executes a command.
 * @args: Array of arguments.
 * Return: 1 if successful, 0 otherwise.
 */
int execute_command(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	if (_strcmp(args[0], "cd") == 0)
	{
		return (change_directory(args));
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		return (echo(args));
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		return (exit_shell(args));
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		return (set_environment(args));
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		return (unset_environment(args));
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		return (handle_alias(args));
	}
	else if (_strcmp(args[0], "run_script") == 0)
	{
		return (run_script(args[1]));
	}
	else
	{
		return (launch(args));
	}
}

/**
 * launch - Launches a new process to execute given command
 * @args: Array of strings
 * Return: 1 on success, or -1 on failure
 */
int launch(char **args)
{
	char **environ = NULL;
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{    /*child process*/
		char *path = getenv("PATH");
		char *dir = strtok(path, ":");

		while (dir != NULL)
		{
			char *command_path = malloc(strlen(dir) + strlen(args[0]) + 2);

			sprintf(command_path, "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				break;
			}
			free(command_path);
			dir = strtok(NULL, ":");
		}
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");/*fork error*/
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
