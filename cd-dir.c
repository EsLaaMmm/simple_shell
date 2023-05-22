#include "shell.h"

/**
 * change_directory - change the current working directory
 * @args: the arguments passed to shell
 * Return: 1 on success, 0 on failure
 */
int change_directory(char **args)
{
	char *new_dir = getcwd(NULL, 0);
	char *prev_dir = getenv("OLDPWD");

	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (prev_dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
		}
		else
		{
			if (chdir(prev_dir) != 0)
			{
				perror("cd");
			}
			printf("%s\n", prev_dir);
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
	if (new_dir == NULL)
	{
		handle_error("getcwd failed");
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", new_dir, 1);
	free(new_dir);
	return (1);
}
