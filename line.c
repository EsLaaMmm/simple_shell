#include "shell.h"

/**
 * _getline - Reads entire line from a stream and allocates memory.
 * @ptr_line: Pointer to a buffer that will contain the read line
 * @n: Pointer to the size of the buffer
 * @ptr_stream: Pointer to the stream to read from
 * Return: Number of chars read, or -1 if error occurred
 */
ssize_t _getline(char **ptr_line, size_t *n, FILE *ptr_stream)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t chars_read = 0;
	int c;
	char *new_line;

	if (!ptr_line || !n || !ptr_stream)
	{
		errno = EINVAL;
		return (-1);
	}
	while ((c = getc(ptr_stream)) != EOF)
	{
		if (size <= (size_t)chars_read + 1)
		{
			size = (size + 1) * 2;
			new_line = realloc(line, size);
			if (!new_line)
			{
				free(line);
				return (-1);
			}
			line = new_line;
		}
		line[chars_read++] = c;
		if (c == '\n')
		{
			break;
		}
	}
	if (chars_read == 0)
	{
		free(line);
		return (-1);
	}
	line[chars_read] = '\0';
	*ptr_line = line;
	*n = size;

	return (chars_read);
}

/**
 * read_line - Reads line from stdin
 * Return:  Pointer to the line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t size_of_buffer = 0;

	if (_getline(&line, &size_of_buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			handle_error("read_line failed");
		}
	}
	return (line);
}

