#include "shell.h"

/**
 * init_sh - runs the shell in interactive mode
 *
 * Return: void
 */

void init_sh(void)
{
	char *cmd = NULL;
	size_t _buf = 0;

	if (isatty(fileno(stdin)))
	{
		while (1)
		{
			prmpt();
			if (getline(&cmd, &_buf, stdin) == -1)
			{
				printf("\n");
				break;
			}
			if (_strlen(cmd) <= 1)
				continue;
			if (exec_cmd(cmd) == -1)
			{
				free(cmd);
				perror(cmd);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		if (getline(&cmd, &_buf, stdin) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (exec_cmd(cmd) != 0)
			{
				perror("Error");
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * usr_cmd - receives the user input from stdin
 * @argc: argument counter
 * @argv: pointer to array of arguments
 *
 * Return: void.
 */

void usr_cmd(int argc, char *argv[])
{
	if (argc > 1)
	{
		int arg_cnt;

		for (arg_cnt = 1; arg_cnt < argc; arg_cnt++)
		{
			if (exec_cmd(argv[arg_cnt]) != 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		init_sh();
	}
}
