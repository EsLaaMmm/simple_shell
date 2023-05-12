#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 64
#define MAX_ARGUMENTS 100

/* MAIN FILE */
char command[MAX_COMMAND_SIZE];
char *args[MAX_ARGUMENTS];
extern char **environ;
