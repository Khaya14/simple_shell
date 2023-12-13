#include "shell.h"

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
		int arg_cnt, fd;

		for (arg_cnt = 1; arg_cnt < argc; arg_cnt++)
		{
			fd = exec_cmd(argv[arg_cnt]);
			if (fd != 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
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
}
