#include "main.h"

/**
 * cigint_ - signal handler within the code.
 *
 * @cig: signal usedd during process
 *
 * Return: nothing
 *
 */

void cigint_(int cig)
{
	if (cig ==  SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prmpt();
		fflush(stdout);
	}
}
