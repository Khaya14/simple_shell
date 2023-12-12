#include "shell.h"

/**
 * usr_cmd - receives a users input from the standard input
 * @cmd: string containing user input from terminal
 * @n: the number of characters in the input string
 *
 * Return: Number of character read
 */
ssize_t usr_cmd(char *cmd, size_t n)
{
	ssize_t num_char;

	num_char = getline(&cmd, &n, stdin);
	if (num_char == -1)
	{
		perror("getline");
		free(cmd);
		return (-1);
	}

	return (num_char);
}
