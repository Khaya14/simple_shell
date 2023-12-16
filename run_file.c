#include "shell.h"

/**
 * open_fail - prints an error to the stdout if a file does not open
 * @f_path: path of the file to be opened
 *
 * Return: 127 on fail, -1 error, else 0 >=
 */
int open_fail(char *f_path)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (127);

	ln = strlen(cmd) + strlen(old_str) + strlen(f_path) + 16;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(old_str);
		return (127);
	}

	strcpy(err, cmd);
	strcat(err, ": ");
	strcat(err, old_str);
	strcat(err, ": Can't open ");
	strcat(err, f_path);
	strcat(err, "\n");

	free(old_str);
	write(STDERR_FILENO, err, ln);
	free(err);
	return (127);
}
/**
 * exec_file - tries to execute a command stored in a file
 * @f_path: file path inputed
 * @result: last command value returned
 *
 * Return: 127 in open fail, -1 error, otherwise 0 >=
 */
int exec_file(char *f_path, int *result)
{
	ssize_t _file, read_b, _i;
	unsigned int ln_sz = 0;
	unsigned int old_sz = 120;
	char *ln, **arr_args, **top;
	char _buf[120];
	int res;

	cmd_log = 0;
	_file = open(f_path, O_RDONLY);
	if (_file == -1)
	{
		*result = open_fail(f_path);
		return (*result);
	}
	ln = malloc(sizeof(char) * old_sz);
	if (!ln)
		return (-1);
	do {
		read_b = read(_file, _buf, 119);
		if (read_b == 0 && ln_sz == 0)
			return (*result);
		_buf[read_b] = '\0';
		ln_sz += read_b;
		ln = r_alloc(ln, old_sz, ln_sz);
		strcat(ln, _buf);
		old_sz = ln_sz;
	} while (read_b);
	for (_i = 0; ln[_i] == '\n'; _i++)
		ln[_i] = ' ';
	for (; _i < ln_sz; _i++)
	{
		if (ln[_i] == '\n')
		{
			ln[_i] = ';';
			for (_i += 1; _i < ln_sz && ln[_i] == '\n'; _i++)
				ln[_i] = ' ';
		}
	}
	replace_var(&ln, result);
	ln_handlr(&ln, ln_sz);
	arr_args = strtok_(ln, " ");
	free(ln);
	if (!arr_args)
		return (0);
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

	res = args_call(arr_args, top, result);

	free(top);
	return (res);
}
