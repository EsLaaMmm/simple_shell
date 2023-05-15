#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: Name of the environment variable
 * @envp: Environment variables
 * Return: Value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name, char **envp)
{
	char *env_var, *value;
	size_t name_len;

	name_len = strlen(name);
	for (; *envp; envp++)
	{
		env_var = *envp;
		if (strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
		{
			value = env_var + name_len + 1;
			return (value);
		}
	}
	return (NULL);
}

/**
 * check_path - Checks if command exists in any of the PATH directories
 * @command: Command to check
 * @envp: Environment variables
 * Return: Full path of command if it exists, otherwise NULL
 */
char *check_path(char *command, char **envp)
{
	char *path =_getenv("PATH",envp);
	char *dir, *fullpath;
	struct stat st;

	/* tokenize PATH variable and check each directory for commands */
	dir = strtok(path, ":");
	while (dir)
	{
		fullpath = malloc(strlen(dir) + strlen(command) + 2);
		if (!fullpath)
			return (NULL);
		strcpy(fullpath, dir);
		strcat(fullpath, "/");
		strcat(fullpath, command);
		if (stat(fullpath, &st) == 0)
		{
			/* command exists */
			free(path);
			return (fullpath);
		}
		free(fullpath);
		dir = strtok(NULL, ":");
	}

	/* command not found */
	free(path);
	return (NULL);
}
