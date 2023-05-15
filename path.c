#include "shell.h"

/**
 * get_path - Returns an array of directories in the PATH
 * @envp: Environment variables
 * Return: Array of directories in the PATH environment variable
 */
char **get_path(char **envp)
{
        char **path = NULL;
        char *path_env;
	char *c;
        char *dir;
        int i, n;

        /* find PATH environment variable */
        for (i = 0; envp[i]; i++)
        {
                if (strncmp(envp[i], "PATH=", 5) == 0)
                {
                        /* allocate memory for path array */
                        path_env = envp[i] + 5;
                        n = 1; /* count number of directories in path */
                        for (c = path_env; *c != '\0'; c++)
                        {
                                if (*c == ':')
                                        n++;
                        }
                        path = malloc(sizeof(char *) * (n + 1));
                        if (!path)
                        {
                                perror("malloc");
                                exit(EXIT_FAILURE);
                        }

                        /* tokenize path_env string */
                        dir = strtok(path_env, ":");
                        for (i = 0; dir; i++)
                        {
                                path[i] = dir;
                                dir = strtok(NULL, ":");
                        }
                        path[i] = NULL;
                        break;
                }
        }

        return (path);
}

/**
 * check_path - Checks if command exists in any of the PATH directories
 * @command: Command to check
 * @envp: Environment variables
 * Return: Full path of command if it exists, otherwise NULL
 */
char *check_path(char *command, char **envp)
{
	char **paths;
	char *path;
	struct stat st;
	int i;

	/* get array of directories in PATH */
	paths = get_path(envp);

	/* check if command exists in each directory */
	for (i = 0; paths && paths[i]; i++)
	{
		/* allocate memory for path string */
		path = malloc(sizeof(char) * (strlen(paths[i]) + strlen(command) + 2));
		if (!path)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* construct path string */
		sprintf(path, "%s/%s", paths[i], command);
		/* check if file exists and is executable */
		if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			/* command found */
			free(paths);
			return (path);
		}
		/* free memory */
		free(path);
	}
	/* command not found */
	free(paths);
	return (NULL);
}
