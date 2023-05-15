#include "shell.h"

/**
 * tokenize - Breaks a string into tokens
 * @str: String to tokenize
 * Return: Array of tokens
 */
char **tokenize(char *str)
{
        char **tokens;
        char *token;
        int i, n;

        /* count number of tokens */
        for (i = 0; str[i]; i++)
        {
                if (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n' || str[i] == '\f' || str[i] == '\v')
                        continue;
                n++;
                while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\n' && str[i] != '\f' && str[i] != '\v')
			i++;
        }

        /* allocate memory for token array */
        tokens = malloc(sizeof(char *) * (n + 1));
        if (!tokens)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }

        /* tokenize string */
	n = 0;
        token = strtok(str, " \t\r\n\f\v");
        while (token)
        {
                tokens[n++] = token;
                token = strtok(NULL, " \t\r\n\f\v");
        }
        tokens[n] = NULL;

        return (tokens);
}
