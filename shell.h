#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/type.h>

#define MAX_COMMAND_SIZE 64

/* MAIN FILE */
char command[MAX_COMMAND_SIZE];
extern char **environ;
