#include "shell.h"

/**
 * tokenize - Breaks a string into tokens
 * @str: String to tokenize
 * Return: Array of tokens
 */
char **tokenize(char *str)
{
        char **tokens = NULL;
        char *token;
        int i = 0;

	/* allocate memory for array */
	tokens = malloc(sizeof(char *));
	if (!tokens)
		return (NULL);
	/* tokenize string */
        token = strtok(str, " \t\n");
        while (token)
        {
		/* add token to array */
                tokens[i] = token;
		i++;
                tokens = realloc(tokens, sizeof(char *) * (i + 1));
		if (!tokens)
			return (NULL);
		token = strtok(NULL, " \t\n");
        }
	/* add NULL terminator to end of array */
        tokens[i] = NULL;

        return (tokens);
}
