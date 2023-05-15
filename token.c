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
        int i, n = 0;

        /* count number of tokens */
        for (i = 0; str[i]; i++)
        {
                if (str[i] == ' ')
                        continue;
                n++;
                while (str[i] && str[i] != ' ')
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
        token = strtok(str, " \n\t");
        for (i = 0; token; i++)
        {
                tokens[i] = token;
                token = strtok(NULL, " \n\t");
        }
        tokens[i] = NULL;

        return (tokens);
}
