#include "shell.h"

/**
 * d_count -  this function counts the number of digits
 * @cmd_nm: the number that the function must count
 *
 * Return: the number of digits the function read
 */
int d_count(size_t cmd_nm)
{
	int d_cnt = 0;

	if (cmd_nm == 0)
		return (1);
	while (cmd_nm != 0)
	{
		cmd_nm /= 10;
		d_cnt++;
	}

	return (d_cnt);
}
