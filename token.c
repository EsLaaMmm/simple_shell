#include "shell.h"

/**
 * tokenize - Breaks a string into tokens
 * @str: String to tokenize
 * Return: Array of tokens
 */
char **tokenize(char *str)
{
	char **tokens = NULL;
	char *token, **new_tokens;
	int i = 0;
	const int token_size = 64;
	int buffer_size = token_size;

	/* allocate memory for array */
	tokens = malloc(sizeof(char *));
	if (!tokens)
		return (NULL);
	/* tokenize string */
	token = strtok(str, " \t\n");
	tokens[0] = NULL;
	while (token)
	{
		/* add token to array */
		tokens[i] = token;
		i++;
		if (i >= buffer_size)
		{
			buffer_size += token_size;
			new_tokens = realloc(tokens, buffer_size * sizeof(char *) * (i + 2));
			if (!new_tokens)
			{
				free(tokens);
				return (NULL);
			}
			tokens = new_tokens;
		}
		token = strtok(NULL, " \t\n");
	}
	/* add NULL terminator to end of array */
	tokens[i] = NULL;

	return (tokens);
}
