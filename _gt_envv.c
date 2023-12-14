#include "shell.h"

/**
 * _gt_envv - function that starts encorporates getenv
 *
 * @file: character constant
 *
 * Return: NULL
 */

char *_gt_envv(const char *file)
{
	unsigned int ind_e, env_len;
	char *var_e;
	char *var_ecp;

	for (ind_e = 0; _env[ind_e]; ind_e++)
	{
		if (strncmp(_env[ind_e], file, strlen(file)) == 0)
		{
			env_len = strlen(_env[ind_e]) - (strlen(file));
			var_e = malloc(sizeof(char) * env_len);
			if (var_e == NULL)
			{
				perror("Error: malloc failed var_e");
				return (NULL);
			}
			ch_mllc(var_ecp, strlen(_env[ind_e]) + 1,
					"malloc error _gt_envv");
			strcpy(var_ecp, _env[ind_e]);
			strncpy(var_e, var_ecp += (strlen(file) + 1), env_len);
			free(var_ecp -= (sttrlen(file) + 1));
			return (var_e);
		}
	}
	return (NULL)
}
