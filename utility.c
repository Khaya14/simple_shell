#include "shell.h"

/**
 * args_free - frees an argument array
 * @arr_args: argument array
 * @top: first element of array
 *
 */
void args_free(char **arr_args, char **top)
{
	size_t _i;

	for (_i = 0; arr_args[_i] || arr_args[_i + 1]; _i++)
		free(arr_args[_i]);

	free(top);
}
/**
 * _getspid - gets the process id of a process
 * Return: buffer
 */
char *_getspid(void)
{
	size_t _i = 0;
	char *_buf;
	ssize_t _file;

	_file = open("/proc/self/stat", O_RDONLY);
	if (_file == -1)
	{
		perror("Cant read file!");
		return (NULL);
	}
	_buf = malloc(120);
	if (!_buf)
	{
		close(_file);
		return (NULL);
	}
	read(_file, _buf, 120);
	while (_buf[_i] != ' ')
		_i++;
	_buf[_i] = '\0';

	close(_file);
	return (_buf);
}
/**
 * getsenv_val - function des
 * @start: arg 1
 * @ln: arg 2
 *
 * Return: string value
 */
char *getsenv_val(char *start, int ln)
{
	char **addr_var;
	char *_replace = NULL, *_buf, *v;

	v = malloc(ln + 1);
	if (!v)
		return (NULL);
	v[0] = '\0';
	strncat(v, start, ln);

	addr_var = _gets_env(v);
	free(v);
	if (addr_var)
	{
		_buf = *addr_var;
		while (*_buf != '=')
			_buf++;
		_buf++;
		_replace = malloc(strlen(_buf) + 1);
		if (_replace)
			strcpy(_replace, _buf);
	}

	return (_replace);
}

/**
 * replace_var - function description
 * @ln: arg 1
 * @result: arg 2
 */
void replace_var(char **ln, int *result)
{
	int jj, jk = 0, length;
	char *_replace = NULL, *old_ln = NULL, *nw_ln;

	old_ln = *ln;
	for (jj = 0; old_ln[jk]; jj++)
	{
		if (old_ln[jj] == '$' && old_ln[jj + 1] &&
				old_ln[jj + 1] != ' ')
		{
			if (old_ln[jj + 1] == '$')
			{
				_replace = _getspid();
				jk = jj + 2;
			}
			else if (old_ln[jj + 1] == '?')
			{
				_replace = _i_toa(*result);
				jk = jj + 2;
			}
			else if (old_ln[jj + 1])
			{
				for (jk = jj + 1; old_ln[jk] &&
						old_ln[jk] != '$' &&
						old_ln[jk] != ' '; jk++)
					;
				length = jk - (jj + 1);
				_replace = getsenv_val(&old_ln[jj + 1], length);
			}
			nw_ln = malloc(jj + strlen(_replace)
					  + strlen(&old_ln[jk]) + 1);
			if (!ln)
				return;
			nw_ln[0] = '\0';
			strncat(nw_ln, old_ln, jj);
			if (_replace)
			{
				strcat(nw_ln, _replace);
				free(_replace);
				_replace = NULL;
			}
			strcat(nw_ln, &old_ln[jk]);
			free(old_ln);
			*ln = nw_ln;
			old_ln = nw_ln;
			jj = -1;
		}
	}
}
