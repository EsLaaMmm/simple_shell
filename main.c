#include "shell.h"

/**
 * main - Unix Command Line Interpreter
 * @argc: Argument count
 * @argv: argumenr vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	pid_t pid;
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
		/* Tokenize command into arguments */
		args[0] = command;
		for (i = 1; i < argc; i++)
			args[i] = argv[i];
		/* Fork a child process to execute command */
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
			printf("\n");
		}
	}
	return (0);
}
