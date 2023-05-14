#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 * Return: Exit status of the shell
 */
int main(int argc, char **argv, char **envp)
{
        char *line = NULL;
        char **args = NULL;
        int status = 0;

        /* loop until user exits shell */
        while (1)
        {
                /* print shell prompt */
                printf("cisfun$ ");

                /* read input from user */
                if (getline(&line, &(size_t){0}, stdin) == -1)
                        return (EXIT_FAILURE);

                /* tokenize input into arguments */
                args = tokenize(line);

                /* check if input is empty */
                if (!args || !*args)
                {
                        free(line);
                        free(args);
                        continue;
                }

                /* exit shell if user enters "exit" */
                if (_strcmp(args[0], "exit") == 0)
                {
                        free(line);
                        free(args);
                        return (status);
                }

                /* check if command exists and execute it */
                status = execute(args, envp);

                /* free memory allocated for line and args */
                free(line);
                free(args);
        }

        return (status);
}
/**
 * execute - Checks if command exists and executes it
 * @args: Array of arguments to the command
 * @envp: Environment variables
 * Return: Exit status of executed command
 */
int execute(char **args, char **envp)
{
        pid_t pid;
        int status;
        char *path;
        struct stat st;

        /* check if command exists */
        path = check_path(args[0], envp);
        if (!path)
        {
                printf("%s: command not found\n", args[0]);
                return (127);
        }
        /* create child process */
        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                return (EXIT_FAILURE);
        }
        if (pid == 0)
        {
                /* execute command in child process */
                if (execve(path, args, envp) == -1)
                {
                        perror("execve");
                        _exit(EXIT_FAILURE);
                }
        }
	/* wait for child process to complete */
        if (waitpid(pid, &status, 0) == -1)
        {
                perror("waitpid");
                return (EXIT_FAILURE);
        }
        /* get exit status of child process */
        if (WIFEXITED(status))
                status = WEXITSTATUS(status);

        /* free memory allocated for path */
        free(path);

        return (status);
}
