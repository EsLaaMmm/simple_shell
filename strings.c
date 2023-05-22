#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @str1: First string
 * @str2: Second string
 * Return: An integer
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strlen - Calculates the length of a string
 * @str: String to calculate
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str && *str)
	{
		len++;
		str++;
	}

	return (len);
}
