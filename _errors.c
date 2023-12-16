#include "shell.h"

/**
 * env_error - creates an error message for env errors
 * @arr_args: argument array passes
 *
 * Return: string holding error message
 */
char *env_error(char **arr_args)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (NULL);

	arr_args--;
	ln = strlen(cmd) + strlen(old_str) + strlen(arr_args[0]) + 45;
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
	strcat(err, ": Could not add/remove from environment\n");

	free(old_str);
	return (err);
}

/**
 * al_error -  error message for alias
 * @arr_args: argument array
 *
 * Return: error message
 */
char *al_error(char **arr_args)
{
	char *err;
	int ln;

	ln = strlen(cmd) + strlen(arr_args[0]) + 13;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
		return (NULL);

	strcpy(err, "alias_: ");
	strcat(err, arr_args[0]);
	strcat(err, " not found\n");

	return (err);
}

/**
 * exit_error - error message for exit fail
 * @arr_args: array from the stdin
 *
 * Return: error message
 */
char *exit_error(char **arr_args)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (NULL);

	ln = strlen(cmd) + strlen(old_str) + strlen(arr_args[0]) + 27;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(old_str);
		return (NULL);
	}

	strcpy(err, cmd);
	strcat(err, ": ");
	strcat(err, old_str);
	strcat(err, ": exit: Illegal number: ");
	strcat(err, arr_args[0]);
	strcat(err, "\n");

	free(old_str);
	return (err);
}

/**
 * cd_error - error message for cd command
 * @arr_args: array pointer
 *
 * Return: array pointer
 */
char *cd_error(char **arr_args)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (NULL);

	if (arr_args[0][0] == '-')
		arr_args[0][2] = '\0';
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
	if (arr_args[0][0] == '-')
		strcat(err, ": cd: Illegal command ");
	else
		strcat(err, ": _cd: can't cd to ");
	strcat(err, arr_args[0]);
	strcat(err, "\n");

	free(old_str);
	return (err);
}
/**
 * syntax_error - syntax error message
 * @arr_args: array of arguments
 *
 * Return: error message
 */
char *syntax_error(char **arr_args)
{
	char *err, *old_str;
	int ln;

	old_str = _i_toa(cmd_log);
	if (!old_str)
		return (NULL);

	ln = strlen(cmd) + strlen(old_str) + strlen(arr_args[0]) + 33;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(old_str);
		return (NULL);
	}

	strcpy(err, cmd);
	strcat(err, ": ");
	strcat(err, old_str);
	strcat(err, ": Syntax error: \"");
	strcat(err, arr_args[0]);
	strcat(err, "\" unexpected\n");

	free(old_str);
	return (err);
}
