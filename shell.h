#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 64

char* tokens[MAX_NUM_TOKENS];
int numTokens = 0;
