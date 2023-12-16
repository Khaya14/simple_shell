#include "shell.h"

/**
 * cp_env - copies the environment variable
 *
 * Return: null on success
 */
char **cp_env(void)
{
	char **nw_env;
	size_t sz;
	int _i;

	for (sz = 0; environ[sz]; sz++)
		;

	nw_env = malloc(sizeof(char *) * (sz + 1));
	if (!nw_env)
		return (NULL);

	for (_i = 0; environ[_i]; _i++)
	{
		nw_env[_i] = malloc(strlen(environ[_i]) + 1);

		if (!nw_env[_i])
		{
			for (_i--; _i >= 0; _i--)
				free(nw_env[_i]);
			free(nw_env);
			return (NULL);
		}
		strcpy(nw_env[_i], environ[_i]);
	}
	nw_env[_i] = NULL;

	return (nw_env);
}

/**
 * env_free - frees an environment variable
 */
void env_free(void)
{
	int _i;

	for (_i = 0; environ[_i]; _i++)
		free(environ[_i]);
	free(environ);
}

/**
 * _gets_env - gets the environ from a PATH
 * @s: name of var to get from PATH
 *
 * Return: NULL on error, else name of variable
 */
char **_gets_env(const char *s)
{
	int _i, ln;

	ln = strlen(s);
	for (_i = 0; environ[_i]; _i++)
	{
		if (strncmp(s, environ[_i], ln) == 0)
			return (&environ[_i]);
	}

	return (NULL);
}
