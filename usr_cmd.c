#include "shell.h"

/**
 * usr_cmd - receives the user input from stdin
 * @cmd: A character string received from stdin
 * @n_ch: the number of charaters in string cmd
 * @args: pointer to array of string tokens
 *
 * Return: void.
 */
void usr_cmd(char *cmd, size_t n_ch, char **args)
{
	char *token;
	int i = 0;

	if (args == NULL)
	{
		perror("argv");
		exit(EXIT_FAILURE);
	}
	if (getline(&cmd, &n_ch, stdin) == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	else
	{
		token = strtok(cmd, " \n\t");
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		args[i] = NULL;
	}
}
