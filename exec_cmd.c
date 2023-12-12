#include "shell.h"

/**
 * exec_cmd - executes the users input
 * @cmd: the character string to be executed
 *
 * Return: void
 */
void exec_cmd(char **args)
{
	int status;
	pid_t kind_pid = fork();

	if (kind_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (kind_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
