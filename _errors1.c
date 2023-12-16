#include "shell.h"

/**
 * err_permission - permission error message
 * @arr_args: argument array..
 *
 * Return: error message
 */
char *err_permission(char **arr_args)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (NULL);

	ln = strlen(cmd) + strlen(old_str) + strlen(arr_args[0]) + 24;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(old_str);
		return (NULL);
	}

	strcpy(err, cmd);
	strcat(err, ": ");
	strcat(err, old_str);
	strcat(err, ": ");
	strcat(err, arr_args[0]);
	strcat(err, ": Permissions denied\n");

	free(old_str);
	return (err);
}
/**
 * cmd_error - command does not exist error
 * @arr_args: argument array
 *
 * Return: error message
 */
char *cmd_error(char **arr_args)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (NULL);

	ln = strlen(cmd) + strlen(old_str) + strlen(arr_args[0]) + 16;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(old_str);
		return (NULL);
	}

	strcpy(err, cmd);
	strcat(err, ": ");
	strcat(err, old_str);
	strcat(err, ": ");
	strcat(err, arr_args[0]);
	strcat(err, ": not found\n");

	free(old_str);
	return (err);
}
