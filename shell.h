#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGS 64

extern char environ;

/* MAIN FILE */
void execute_command(char **args);
char **parse_command(char *command);
int check_builtin(char **args);
void print_error(char *command, int code);
void free_args(char **args);
