#include "shell.h"

/**
 * bltn_exit - builtin system call that exits the program
 * @arr_tkns: pointer to an array that holds tokens of the user commands
 *
 * Return: 0 on success, 1 on failure
 */
int bltn_exit(char **arr_tkns)
{
	if (arr_tkns[1] != NULL)
		exit(atoi(arr_tkns[1]));
	else
		return (_BUF_SIZE);
}
