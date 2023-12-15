#include "shell.h"

/**
 * _i_t_oa - this function converts an int to a string
 * uses malloc to allocate memory for the return string
 * @cmd_nm: The number inputed that has to be converted
 *
 * Return: the coverted integer as a string
 */
char *_i_t_oa(size_t cmd_nm)
{
	char *res = malloc(sizeof(char) * (32 + 1));
	int idx = 0;

	do {
		res[idx++] = cmd_nm % 10 + '0';
		cmd_nm /= 10;
	} while (cmd_nm > 0);
	res[idx] = '\0';
	_s_rev(res);

	return (res);
}
