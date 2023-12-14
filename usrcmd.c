#include "shell.h"

/**
 * usrcmd - receives command input from the user.
 *
 * @i: the input received
 * @byt_all: number of bytes allocated
 * @status: exit status
 *
 * Return: Number of characters that are read.
 */

ssize_t usrcmd(char **i, size_t *byt_all, int status)
{
	ssize_t n_ch;

	n_ch = getline(i, byt_all, stdin);
	if (n_ch == -1)
	{
		free(*i);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (n_ch);
}
