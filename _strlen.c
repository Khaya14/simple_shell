#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string to be considered
 *
 * Return: the integer n
 */
int _strlen(char *str)
{
	int i;
	int n = 0;

	for (i = 0; str[i] != '\0'; i++)
		n++;

	return (n);
}
