#include "shell.h"

/**
 * strlen - Computes the length of a string
 * @s: String
 * Return: Length of the string
 */
size_t strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * strcpy - Copies a string
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to destination string
 */
char *strcpy(char *dest, const char *src)
{
	int i;
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to destination string
 */
char *strcat(char *dest, const char *src)
{
	int dest_len = strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return dest;
}
