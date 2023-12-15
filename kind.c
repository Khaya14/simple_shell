#include "shell.h"

/**
 * _kind - funnction that executes a command in a child process.
 *
 * @arr_tkns: array of tokens uses for the command.
 *
 * @cmd: command that will be executed.
 *
 * Return: 0
 */

int _kind(char *cmd, char **arr_tkns)
{
	pid_t kind;
	int status, err_excv;

	kind = fork();
	if (kind == -1)
	{
		perror("Error: Child unable to create. _kind()");
		return (-1);
	}
	if (kind == 0)
	{
		if (strcmp(cmd, "/bin/ls") || strcmp(cmd, "ls"))
		{
			if (setenv("LC_COLLATE", "en_US.utf8", 1) != 0)
			{
				perror("Error setting LC_COLLATE");
				return (-1);
			}
		}
		err_excv = execve(cmd, arr_tkns, __environ);
		if (err_excv == -1)
		{
			perror("excv: Error, execve");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(cmd);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
