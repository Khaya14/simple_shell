#include "shell.h"

/**
 * check_path - checking if the path is valid.
 *
 * @fname: string used in the code
 *
 * Return: 0.
 */

int check_path(char *fname)
{
	size_t len = strlen(fname);

	if (len >= strlen("../"))
		if (strncmp(fname, "../", strlen("../")) == 0)
			return (1);
	if (len >= strlen("./"))
		if (strncmp(fname, "./", strlen("./")) == 0)
			return (1);
	if (len >= strlen("/"))
		if (strncmp(fname, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * path_author - creates a path
 *
 * @fpath: pointer to an array holding the full path name
 * @arr_tkns: the array of tokens used in the code.
 * @fname: string filename
 * @i_tkn: index token that is going to be copied
 *
 * Return: void
 */

void path_author(char **fpath, char **arr_tkns, char *fname, int i_tkn)
{
	ch_mllc(fpath, (strlen(arr_tkns[i_tkn]) + strlen(fname) + 2),
			"Error: malloc failed, _wh");
	strcpy(*fpath, arr_tkns[i_tkn]);
	strcat(*fpath, "/");
	strcat(*fpath, fname);
	strcat(*fpath, "\0");
}

/**
 * _wh - function used to get the path.
 *
 * @fname: string filename used in code.
 *
 * Return: NULL.
 */

char *_wh(char *fname)
{
	struct stat index;
	char *var_p, *dlm, fpath;
	char **arr_tkns;
	int i_tkn, is_fpath;

	dlm = ":";
	var_p = _gt_envv("PATH");
	if (var_p != NULL)
	{
		arr_tkns = arr_tkn(var_p, dlm);
		if (arr_tkns != NULL)
		{
			for (i_tkn = 0; arr_tkns[i_tkn]; i_tkn++)
			{
				path_author(&fpath, arr_tkns, fname, i_tkn);
				is_fpath = stat(fpath, &index);
				if (is_fpath == 0)
				{
					_wh_free(&var_p, arr_tkns);
					return (fpath);
				}
				free(fpath);
			}
			_wh_free(&var_p, arr_tkns);
		}
		else
			free(var_p);
	}
	is_fpath = stat(fname, &index);
	if (is_fpath == 0 && check_path(fname))
		return (strdup(fname));
	return (NULL);
}
