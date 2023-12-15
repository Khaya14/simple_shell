#include "shell.h"

/**
 * usrcmd - receives command input from the user.
 *
 * @inp: the input received
 * @byt_all: number of bytes allocated
 * @status: exit status
 *
 * Return: Number of characters that are read.
 */

ssize_t usrcmd(char **inp, size_t *byt_all, int status)
{
	ssize_t n_ch;

	n_ch = getline(inp, byt_all, stdin);
	if (n_ch == -1)
	{
		free(*inp);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (n_ch);
}
