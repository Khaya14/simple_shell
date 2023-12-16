#include "shell.h"

/**
 * ln_num - finds the digit length of an integer
 * @n: the number to be checked
 *
 * Return: the length of the number
 */
int ln_num(int n)
{
	unsigned int digit;
	int ln = 1;

	if (n < 0)
	{
		ln++;
		digit = n * -1;
	}
	else
	{
		digit = n;
	}
	while (digit > 9)
	{
		ln++;
		digit /= 10;
	}

	return (ln);
}

/**
 * _i_toa - converts integer to a character string
 *@n: the integer
 *
 * Return: the string
 */
char *_i_toa(int n)
{
	char *_buf;
	int ln = ln_num(n);
	unsigned int digit;

	_buf = malloc(sizeof(char) * (ln + 1));
	if (!_buf)
		return (NULL);

	_buf[ln] = '\0';

	if (n < 0)
	{
		digit = n * -1;
		_buf[0] = '-';
	}
	else
	{
		digit = n;
	}

	ln--;
	do {
		_buf[ln] = (digit % 10) + '0';
		digit /= 10;
		ln--;
	} while (digit > 0);

	return (_buf);
}

/**
 * error_creator - writes a special error to the stdout
 * @arr_args: arguments array
 * @err_n: error number
 *
 * Return: error
 *
 */
int error_creator(char **arr_args, int err_n)
{
	char *err;

	switch (err_n)
	{
	case -1:
		err = env_error(arr_args);
		break;
	case 1:
		err = al_error(arr_args);
		break;
	case 2:
		if (*(arr_args[0]) == 'e')
			err = exit_error(++arr_args);
		else if (arr_args[0][0] == ';' || arr_args[0][0] == '&'
				|| arr_args[0][0] == '|')
			err = syntax_error(arr_args);
		else
			err = cd_error(arr_args);
		break;
	case 126:
		err = err_permission(arr_args);
		break;
	case 127:
		err = cmd_error(arr_args);
		break;
	}
	write(STDERR_FILENO, err, strlen(err));

	if (err)
		free(err);
	return (err_n);
}

