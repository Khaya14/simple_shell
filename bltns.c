#include "shell.h"

/**
 * bltn_gets - matches a command to a builtin functions
 * @cmd: arg 1
 *
 * Return: integer
 */
int (*bltn_gets(char *cmd))(char **arr_args, char **top)
{
	bltn_t funx[] = {
		{ "exit", exit_function },
		{ "env", env_function },
		{ NULL, NULL }
	};
	int _i;

	for (_i = 0; funx[_i].file; _i++)
	{
		if (strcmp(funx[_i].file, cmd) == 0)
			break;
	}
	return (funx[_i].d);
}

/**
 * exit_function - exits shell
 * @arr_args: arg 1
 * @top: arg 2
 *
 * Return: integer
 */
int exit_function(char **arr_args, char **top)
{
	int _i, length = 10;
	unsigned int nm = 0, _max_ = 1 << (sizeof(int) * 8 - 1);

	if (arr_args[0])
	{
		if (arr_args[0][0] == '+')
		{
			_i = 1;
			length++;
		}
		for (; arr_args[0][_i]; _i++)
		{
			if (_i <= length && arr_args[0][_i] >= '0' && arr_args[0][_i] <= '9')
				nm = (nm * 10) + (arr_args[0][_i] - '0');
			else
				return (error_creator(--arr_args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (nm > _max_ - 1)
		return (error_creator(--arr_args, 2));
	arr_args -= 1;
	args_free(arr_args, top);
	env_free();
	exit(nm);
}
/**
 * env_function - a function
 * @arr_args: arg 1
 * @top: arg 2
 *
 * Return: integer
 */
int env_function(char **arr_args, char __attribute__((__unused__)) **top)
{
	int _i;
	char not_c = '\n';

	if (!environ)
		return (-1);

	for (_i = 0; environ[_i]; _i++)
	{
		write(STDOUT_FILENO, environ[_i], strlen(environ[_i]));
		write(STDOUT_FILENO, &not_c, 1);
	}

	(void)arr_args;
	return (0);
}
