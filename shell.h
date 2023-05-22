#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

/* MAIN */
void prompt(void);
int main(int argc, char **argv);

/* CHANGE DIRECTORY */
int change_directory(char **args);

/* ECHO COMMAND */
int echo(char **args);

/* ENVIROMENT */
int set_environment(char **args);
int unset_environment(char **args);

/* EXECUTE COMMAND */
int execute_command(char **args);
int launch(char **args);

/* EXIT SHELL */
int exit_shell(char **args);

/* HANDLE ERROR/ALIAS */
void handle_error(char *message);
int handle_alias(char **args);

/* COMMAND INPUT */
int input(char *file_name);
char **parse_input(char *line);
int script(char *file_name);

/* COMMAND LINE */
ssize_t _getline(char **ptr_line, size_t *n, FILE *ptr_stream);
char *read_line(void);

/* STRINGS */
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);

#endif /* SHELL_H */

