#include "shell.h"

/**
 * err_msg - prints an error messeage in a specific format
 *
 * @arr: array with the command
 * @arr_tkns: array with tokens of command
 * @b_allc: counter
 *
 * Return: number of bytes
 */

int err_msg(char **arr, char **arr_tkns, size_t b_allc)
{
	char *err_str;
	char *b_allc_str = _i_t_oa(b_allc);
	int sz = (strlen(arr[0]) + (2 * strlen(": ")) +
		d_count(b_allc) + strlen(arr_tkns[0]) +
		strlen(": not found\n") + 1);

	ch_mllc(&err_str, sz, "err_msg Err: mllc err");
	strcpy(err_str, arr[0]);
	strcat(err_str, ": ");
	strcat(err_str, b_allc_str);
	strcat(err_str, ": ");
	strcat(err_str, arr_tkns[0]);
	strcat(err_str, ": not found\n");
	strcat(err_str, "\0");

	write(STDERR_FILENO, err_str, strlen(err_str));
	free(err_str);
	free(b_allc_str);
	return (128);
}
