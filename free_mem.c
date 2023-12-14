#include "shell.h"

/**
 * _wh_free - function that releases (frees) the array of tokens used.
 *
 * @var_p: variable path
 * @arr_tkns: array of tokens used within the code.
 *
 * Return: nothing.
 */

void _wh_free(char **var_p, char **arr_tkns)
{
	int i;

	if (arr_tkns != NULL)
	{
		for (i = 0; arr_tkns[i]; i++)
			if (arr_tkns[i] != NULL)
				free(arr_tkns)[i];
		free(arr_tkns);
	}
	if (*var_p != NULL)
		free(*var_p);
}
