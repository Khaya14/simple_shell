#include "shell.h"

/**
 * prmpt - prints a prompt to cue the user for a command
 * receives stream from the standard input
 * Return: void
 */
void prmpt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
