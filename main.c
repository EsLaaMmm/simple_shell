#include "shell.h"

char *_getenv(const char *name);

/**
 * main - Unix Command Line Interpreter
 * Return: 0
 */
int main(void)
{
	pid_t pid;
	char *args[MAX_ARGS], *token, *command = NULL, *path = NULL;
	size_t bufsize = 0;
	int status, i = 0;
	char *command_path = malloc(strlen(token) + strlen(args[0]) + 2);

	path = _getenv("PATH"):

	while (1)
	{
		/* Display prompt and wait for user input */
		printf("#cisfun$ ");
		fflush(stdout);
		/* Read user input */
		if (getline(&command, &bufsize, stdin) == -1)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';
		/* Split input into tokens */
		token = strtok(command, " ");
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		/* Checks for built-in command */
		if (strcmp(args[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(args[0], "cd") == 0)
		{
			if (args[1] == NULL)
			{
				/* Change to home directory */
				chdir(_getenv("HOME"));
			}
			else if (chdir(args[1]) == -1)
			{
				perror("cd");
			}
			continue;
		}
		/* Search for command in PATH */
		path = _getenv("PATH");
		token = strtok(path, ":");
		while (token != NULL)
		{
			sprintf(command_path, "%s/%s", token, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				break;
			}
			free(command_path);
			token = strtok(NULL, ":");
		}
		/* Fork a child process to execute command */
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			waitpid(pid, &status, 0);
		}
	}
	free(command);
	return (0);
}

/**
 * _getenv - Gets the value of an enviroment variable
 * @name: Name of the variable
 * Return: Value of the variable or NULL if not found
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);
	char *env, *result = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = (environ[i]);
		if (strcmp(env, name) == 0 && env[len] == '=')
		{
			return (&env[len + 1]);
			break;
		}
	}
	return (result);
}
