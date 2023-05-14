#include "shell.h"

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
	paths = get_paths(envp);

	/* check if command exists in each directory */
	for (i = 0; paths && paths[i]; i++){
		/* allocate memory for path string /
		   path = malloc(sizeof(char) * (strlen(paths[i]) + strlen(command) + 2));
		   if (!path) {
		   perror("malloc");
		   exit(EXIT_FAILURE);
		   }
		   / construct path string /
		   sprintf(path, "%s/%s", paths[i], command);
		   / check if file exists and is executable /
		   if (stat(path, &st) == 0 && st.st_mode & S_IXUSR) {
		   / command found /
		   free(paths);
		   return path;
		   }
		   / free memory /
		   free(path);
		   }
		   / command not found */
		free(paths);
	return NULL;
}
