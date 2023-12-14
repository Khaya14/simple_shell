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
				free(arr_tkns[i]);
		free(arr_tkns);
	}
	if (*var_p != NULL)
		free(*var_p);
}

/**
 * mem_free - function that will free allocated memory to the array of tokens
 * and free the memory allocated to the user input
 * @arr_tkns: array of tokens containing user commands
 * @inp: an array holding the user input
 * Return: void
 */
void mem_free(char **arr_tkns, char *inp)
{
	int i;

	for (i = 0; arr_tkns[i]; i++)
		free(arr_tkns[i]);
	free(arr_tkns);
	free(inp);
}
