#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGUMENTS 128

/* MAIN FILE */
int execute(char **args, char **envp);

/* PATH */
char *check_path(char *command, char **envp);

