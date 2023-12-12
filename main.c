#include "shell.h"

/**
 * main - initiates a shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *cmd = NULL;
	size_t n_ch = 0;
	char **args;

	args = malloc(sizeof(char *) * 1024);
	while (1)
	{
		prmpt();
		usr_cmd(cmd, n_ch, args);
		exec_cmd(args);
	}
	free(args);
	return (0);
}
