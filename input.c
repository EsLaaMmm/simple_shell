#include "shell.h"

/**
 * input - Reads file and executes the commands
 * @file_name: Name of the file to read
 * Return: 0 on success, 1 on failure
 */
int input(char *file_name)
{
	FILE *fp = fopen(file_name, "r");
	char *line = NULL;
	size_t buffer_size = 0;
	int status = 0;

	if (fp == NULL)
	{
		perror("input");
		return (1);
	}

	while (_getline(&line, &buffer_size, fp) != -1)
	{
		char **args = parse_line(line);

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				status = exit_shell(args);

			}
			else
			{
				status = execute_command(args);
			}
		}
		free(args);
		if (status != 0)
		{
			break;
		}
	}
	free(line);
	fclose(fp);
	return (status);
}

/**
 * parse_input - Parses a line of input into an array of tokens
 * @line: The line of input to be parsed
 * Return: An array of tokens, or NULL if there was an error
 */
char **parse_input(char *line)
{
	int size_of_buffer = BUFFER_SIZE;
	int pos = 0;
	char **tokens = malloc(size_of_buffer * sizeof(char *));
	char *token;

	if (!tokens)
	{
		handle_error("parse_input failed: allocation error");
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[pos] = token;
		pos++;
		if (pos >= size_of_buffer)
		{
			size_of_buffer += BUFFER_SIZE;
			tokens = realloc(tokens, size_of_buffer * sizeof(char *));
			if (!tokens)
			{
				handle_error("parse_input failed: allocation error");
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[pos] = NULL;
	return (tokens);
}
