#include "shell.h"

/**
 * args_get - collects argument
 * @ln: arg 1
 * @result: arg 2
 *
 * Return: character string
 */
char *args_get(char *ln, int *result)
{
	size_t nm = 0;
	ssize_t rd;
	char *my_prompt = "$ ";

	if (ln)
		free(ln);

	rd = _get_line(&ln, &nm, STDIN_FILENO);
	if (rd == -1)
		return (NULL);
	if (rd == 1)
	{
		cmd_log++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, my_prompt, 2);
		return (args_get(ln, result));
	}

	ln[rd - 1] = '\0';
	replace_var(&ln, result);
	ln_handlr(&ln, rd);

	return (ln);
}

/**
 * args_call - calls an argument
 * @arr_args: arg 1
 * @top: arg 2
 * @result: arg 3
 *
 * Return: integer
 */
int args_call(char **arr_args, char **top, int *result)
{
	int res, _i;

	if (!arr_args[0])
		return (*result);
	for (_i = 0; arr_args[_i]; _i++)
	{
		if (strncmp(arr_args[_i], "||", 2) == 0)
		{
			free(arr_args[_i]);
			arr_args[_i] = NULL;

			res = args_run(arr_args, top, result);
			if (*result != 0)
			{
				arr_args = &arr_args[++_i];
				_i = 0;
			}
			else
			{
				for (_i++; arr_args[_i]; _i++)
					free(arr_args[_i]);
				return (res);
			}
		}
		else if (strncmp(arr_args[_i], "&&", 2) == 0)
		{
			free(arr_args[_i]);
			arr_args[_i] = NULL;

			res = args_run(arr_args, top, result);
			if (*result == 0)
			{
				arr_args = &arr_args[++_i];
				_i = 0;
			}
			else
			{
				for (_i++; arr_args[_i]; _i++)
					free(arr_args[_i]);
				return (res);
			}
		}
	}
	res = args_run(arr_args, top, result);
	return (res);
}

/**
 * args_run - runs an arguments
 * @arr_args: arg 1
 * @top: arg 2
 * @result: arg 3
 *
 * Return: integer
 */
int args_run(char **arr_args, char **top, int *result)
{
	int res, _i;
	int (*bltn)(char **arr_args, char **top);

	bltn = bltn_gets(arr_args[0]);

	if (bltn)
	{
		res = bltn(arr_args + 1, top);
		if (res != _EXIT)
			*result = res;
	}
	else
	{
		*result = exec_cmd(arr_args, top);
		res = *result;
	}

	cmd_log++;

	for (_i = 0; arr_args[_i]; _i++)
		free(arr_args[_i]);

	return (res);
}
/**
 * args_handlr - handles an argument
 * @result: arg 1
 *
 * Return: integer
 */
int args_handlr(int *result)
{
	int res = 0, _i;
	char **arr_args, *ln = NULL, **top;

	ln = args_get(ln, result);
	if (!ln)
		return (_EOF);

	arr_args = strtok_(ln, " ");
	free(ln);
	if (!arr_args)
		return (res);
	if (args_check(arr_args) != 0)
	{
		*result = 2;
		args_free(arr_args, arr_args);
		return (*result);
	}
	top = arr_args;

	for (_i = 0; arr_args[_i]; _i++)
	{
		if (strncmp(arr_args[_i], ";", 1) == 0)
		{
			free(arr_args[_i]);
			arr_args[_i] = NULL;
			res = args_call(arr_args, top, result);
			arr_args = &arr_args[++_i];
			_i = 0;
		}
	}
	if (arr_args)
		res = args_call(arr_args, top, result);

	free(top);
	return (res);
}

/**
 * args_check - checks an argument
 * @arr_args: arg 1
 *
 * Return: integer
 */
int args_check(char **arr_args)
{
	size_t _i;
	char *_curr, *_next;

	for (_i = 0; arr_args[_i]; _i++)
	{
		_curr = arr_args[_i];
		if (_curr[0] == ';' || _curr[0] == '&' || _curr[0] == '|')
		{
			if (_i == 0 || _curr[1] == ';')
				return (error_creator(&arr_args[_i], 2));
			_next = arr_args[_i + 1];
			if (_next && (_next[0] == ';' || _next[0] == '&' || _next[0] == '|'))
				return (error_creator(&arr_args[_i + 1], 2));
		}
	}
	return (0);
}
