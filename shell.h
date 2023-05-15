#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGUMENTS 128

/* MAIN FILE */
int execute(char **args, char **envp);

/* TOKENIZE */
char **tokenize(char *line);

/* PATH */
char **get_paths(char **envp);
char *check_path(char *command, char **envp);

#endif
