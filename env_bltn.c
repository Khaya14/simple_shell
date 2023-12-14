#include "shell.h"

/**
 * env_bltn - prints the environment variables available
 *
 * @arr_tkn: array of tokens that contain the command to be executed
 *
 * Return: the number of variables printed
 *
 */
int env_bltn(__attribute((unused)) char **arr_tkn)
{
	int i_env;

	for (i_env = 0; __environ[i_env]; i_env++)
	{
		write(STDOUT_FILENO, __environ[i_env], strlen(__environ[i_env]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (i_env);
}
