#include "shell.h"

/**
 * bltn_check -  checks if the command is a builtin in system call
 * @arr_tkns: array of tokens holding user commands
 *
 * Return: 0 means succes
 */
int bltn_check(char **arr_tkns)
{
	int i_bltn;
	const struct bltn_cmd bltn[] = {
		{"env", env_bltn},
		{"exit", bltn_exit},
		{NULL, NULL}
	};

	if (arr_tkns == NULL)
		return (0);
	if (arr_tkns[0] == NULL)
		return (0);

	for (i_bltn = 0; bltn[i_bltn].file != NULL; i_bltn++)
		if (strcmp(arr_tkns[0], bltn[i_bltn].file) == 0)
			return (1);
	return (0);
}

/**
 * bltn_exec - executes a function that matches a builtin system call
 * @arr_tkns: array of tokens holding user commands
 *
 * Return: 0 means success
 */
int bltn_exec(char **arr_tkns)
{
	int i_bltn;
	const struct bltn_cmd bltn[] = {
		{"env", env_bltn},
		{"exit", bltn_exit},
		{NULL, NULL}
	};

	if (arr_tkns == NULL)
		return (0);
	if (arr_tkns[0] == NULL)
		return (0);

	for (i_bltn = 0; bltn[i_bltn].file != NULL; i_bltn++)
		if (strcmp(arr_tkns[0], bltn[i_bltn].file) == 0)
			return (bltn[i_bltn].func(arr_tkns));
	return (0);
}
