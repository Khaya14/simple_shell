#include "shell.h"

/**
 * exec_cmd - creates the child process that executes
 * the user's command/input
 * @cmd: the user input
 *
 * Return: void
 */
void exec_cmd(char *cmd)
{
	int status;
	pid_t kind_pid;
	char **array;

	array = malloc(sizeof(char *) * 1024);
	kind_pid = fork();
	if (kind_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (kind_pid == 0)
	{
		array[0] = cmd;
		array[1] = NULL;
		if (execve(array[0], array, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
