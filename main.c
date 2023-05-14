#include "shell.h"

/**
 * handle_args - execute command with arguments
 * @command: command to execute
 * @args: arguments for command
 * Return: 0 on success, 1 on failure
 */
int handle_args(char *command, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(command, args, environ) == -1)
		{
			printf("%s: command not found\n", command);
			exit(1);
		}
	}
	else if (pid < 0)
	{
		/* Handle fork error */
		printf("Fork failed\n");
		exit(1);
	}
	else
	{
		/* Parent process */
		waitpid(pid, NULL, 0);
	}
	return (0);
}
/**
 * main - Unix Command Line Interpreter
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_SIZE];
	char *args[MAX_ARGUMENTS] = {NULL};
	int i;

	while (1)
	{
		/* Display prompt and wait for user input */
		printf("#cisfun$ ");
		fflush(stdout);
		if (fgets(command, MAX_COMMAND_SIZE, stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			exit(0);
		}
		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';
		/* Parse command line into arguments */
		args[0] = strtok(command, " ");
		for (i = 1; i < MAX_ARGUMENTS && args[i - 1] != NULL; i++)
			args[i] = strtok(NULL, " ");
		/* Handle empty command */
		if (args[0] == NULL)
			continue;
		/* Handle built-in commands */
		if (strcmp(args[0], "exit") == 0)
			exit(0);
		/* Execute command with arguments */
		handle_args(args[0], args);
	}
	return (0);
}

